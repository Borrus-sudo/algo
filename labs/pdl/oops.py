from abc import ABC, abstractmethod


class Shape(ABC):
    @abstractmethod
    def area(self):
        print(-1)


class Square(Shape):
    def __init__(self, side):
        self.side = side

    def area(self):
        print(self.side**2)


s = Square(4)
s.area()
