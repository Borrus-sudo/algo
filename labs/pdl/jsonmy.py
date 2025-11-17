import json


class DB1:
    records = []
    cols = ["name", "age"]

    def __init__(self, path="./db.json"):
        self.path = path
        self.read()

    def read(self):
        with open(self.path, "r") as file:
            jsonstr = file.read().strip()
            print("blank", jsonstr)
            if jsonstr:
                self.records = json.loads(jsonstr)
        return

    def add(self, name, age):
        self.records.append(dict(name=name, age=(age)))

    def save(self):
        with open(self.path, "w") as file:
            jsonoutput = json.dumps(self.records)
            file.write(jsonoutput)

    def delete(self, name):
        for idx, record in enumerate(self.records):
            if record["name"] == name:
                self.records.pop(idx)


db = DB1()
# db.add("Alan", 100)
# db.add("C.A.R Hoare", 100)
db.add("Dennis Ritchie", 200)
# db.delete("Alan")
db.save()
