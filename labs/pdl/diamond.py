class A:
    def __init__(self):
        print("A")

    def show(self):
        print("A")


class B(A):
    def __init__(self):
        print("B")

    def show(self):
        print("B")


class C(A):
    def __init__(self):
        print("C")

    def show(self):
        print("C")


class D(B, C):
    def __init__(self):
        print("D")

    def show(self):
        print("D")
        super().show()


print(D.mro())
d = D()
d.show()
