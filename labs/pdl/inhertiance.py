class A:
    def __init__(self):
        self.a = 1

    def show(self):
        print(self.a)


class B(A):
    def __init__(self):
        self.a = 2
        super().__init__()

    def show(self):
        super().show()
        print(self.a)


b = B()
b.show()



