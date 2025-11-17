import csv


class DB:
    records = []
    cols = ["name", "age"]

    def __init__(self, path="./db.csv"):
        self.path = path
        self.read()

    def read(self):
        lines = []

        with open(self.path, "r", newline="") as file:
            reader = csv.DictReader(file)
            for row in reader:
                lines.append(row)
            # lines = file.read().split("\n")
        self.records = lines
        return
        if len(lines):
            lines.pop(0)

        for line in lines:
            if not line:
                continue
            record = {}
            parts = line.split(",")
            for col, part in zip(self.cols, parts):
                record[col] = part
            self.records.append(record)

    def add(self, name, age):
        self.records.append(dict(name=name, age=str(age)))

    def save(self):
        #     lines = [",".join(self.cols)]
        #     for record in self.records:
        #         lines.append(",".join(record.values()))
        with open(self.path, "w", newline="") as file:
            writer = csv.DictWriter(file, fieldnames=self.cols)
            writer.writeheader()
            writer.writerows(self.records)

    def delete(self, name):
        for idx, record in enumerate(self.records):
            if record["name"] == name:
                self.records.pop(idx)


db = DB()
db.delete("Alan")
# db.add("Alan", 100)
# db.add("C.A.R Hoare", 100)
# db.add("Dennis Ritchie", 200)
db.save()
