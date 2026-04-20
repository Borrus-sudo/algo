class SuperClass:
    def __init__(self):
        pass
    
    def A(self):
        self.B()
    
    def B(self):
        print("Super Class")
        
class SubClass(SuperClass):
    def __init__(self):
        super().__init__()
        
    def B(self):
        print("Sub Class")
    
    def C(self):
        self.A()                
        
        
obj = SubClass()
obj.C()