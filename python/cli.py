todos = []

while True:
    if len(todos) == 0:
        print("No todos!")
    gen = input("[A]dd todo/[R]emove todo/[M]odify todo/ [E]xit ")
    if gen != "A" and gen != "R" and gen != "M" and gen != "E":
        continue
    if gen == 'E':
        break
    if gen == "R":
        if len(todos) == 0:
            print("No todos")
            continue
        while True:
            num = int(input("Enter todo number: "))
            if num < 1 or num > len(todos):
                continue
            todos.pop(num - 1)
            break

    if gen == "A":
        todo = input("Add todo: ")
        todos.append(todo)

    if gen == "M":
        if len(todos) == 0:
            print("No todos")
            continue
        while True:
            num = int(input("Enter todo number: "))
            if num < 1 or num > len(todos):
                print("Invalid todo")
                continue
            todo = input("Enter todo: ")
            todos[num - 1] = todo
            break

    idx = 1
    for todo in todos:
        print(f"{idx}. {todo}")
        idx += 1
