class DB:
    content = ""
    loc = "./password.txt"

    def __init__(self):
        pass

    def load(self):
        with open(self.loc, "r") as f:
            self.content = f.read()
        return self.content

    def add(self, user):
        self.content += f"{user["username"]}:{user["password"]}\n"

    def save(self):
        with open(self.loc, "w") as f:
            f.write(self.content)


class AuthSys:
    currUser = ""
    allUsers = None
    db = None

    def __init__(self):
        self.db = DB()
        self.allUsers = []
        self.content = self.db.load()
        if self.content != "":
            for record in self.content.split("\n"):
                if record != "":
                    [username, password] = record.split(":")
                    self.allUsers.append({"username": username, "password": password})

    def login(self, user):
        # allUsers can be a better data structure ig
        for record in self.allUsers:
            if user["username"] == record["username"] and user["password"] == record["password"]:
                return "1"
            elif user["username"] == record["username"] and user["password"] != record["password"]:
                return "0"
        return "2"

    def signup(self, user):
        self.allUsers.append(user)
        self.db.add(user)
        self.db.save()
        pass


class UI:
    auth = None
    state = "logged-out"
    user = None

    def __init__(self):
        self.auth = AuthSys()

    def isLogged(self):
        return self.state == "logged"

    def loop(self):
        while True:
            if self.isLogged():
                print(f"Welcome {self.user["username"]}!")
                print("[1]. Exit")
                print("[2]. Log Out")
                while True:
                    try:
                        opt = int(input("[1]/[2]: "))
                        if opt == 1:
                            return
                        elif opt == 2:
                            print("Logged Out")
                            self.user = None
                            self.state = "logged-out"
                            break
                        else:
                            print("Please enter a valid number!")
                    except ValueError:
                        print("Please enter a valid number!")
            else:
                # User is not logged
                username = input("Enter username: ")
                password = input("Enter password: ")
                user = {"username": username, "password": password}
                res = self.auth.login(user)
                if res == "1":
                    self.user = user
                    self.state = "logged"
                    continue
                elif res == "0":
                    print("Wrong Password!")
                    continue
                while True:
                    resp = input(
                        "Username doesn not exist, do you want to signup [Y/N]: "
                    )
                    if resp == "Y":
                        self.auth.signup(user)
                        self.state = "logged"
                        self.user = user
                        break
                    elif resp == "N":
                        break
                    print("Enter [Y/N] only!")


if __name__ == "__main__":
    ui = UI()
    ui.loop()
