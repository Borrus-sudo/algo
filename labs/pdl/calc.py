import tkinter as tk

COLORS = {
    "bg": "#1e1e2e",  # base
    "fg": "#cdd6f4",  # text
    "button": "#313244",  # surface0
    "button_text": "#cdd6f4",
    "operator": "#f38ba8",  # red
    "equals": "#a6e3a1",  # green
    "display": "#181825",  # mantle
    "display_text": "#f5e0dc",  # rosewater
}


class Calculator:
    def __init__(self, root):
        self.root = root
        root.title("Catppuccin Mocha Calculator")
        root.configure(bg=COLORS["bg"])
        root.resizable(False, False)

        self.expression = ""

        # Display
        self.display = tk.Entry(
            root,
            font=("Consolas", 22),
            bg=COLORS["display"],
            fg=COLORS["display_text"],
            bd=0,
            justify="right",
            insertbackground=COLORS["display_text"],
        )
        self.display.grid(
            row=0, column=0, columnspan=4, sticky="nsew", padx=10, pady=10, ipady=15
        )

        # Buttons
        buttons = [
            ("7", 1, 0),
            ("8", 1, 1),
            ("9", 1, 2),
            ("/", 1, 3),
            ("4", 2, 0),
            ("5", 2, 1),
            ("6", 2, 2),
            ("*", 2, 3),
            ("1", 3, 0),
            ("2", 3, 1),
            ("3", 3, 2),
            ("-", 3, 3),
            ("0", 4, 0),
            (".", 4, 1),
            ("C", 4, 2),
            ("+", 4, 3),
            ("=", 5, 0),
        ]

        for text, row, col in buttons:
            self.make_button(text, row, col)

        # Equals button spans all columns
        self.root.grid_rowconfigure(5, weight=1)
        tk.Button(
            root,
            text="=",
            command=self.calculate,
            bg=COLORS["equals"],
            fg=COLORS["bg"],
            font=("Consolas", 22),
            bd=0,
            activebackground=COLORS["equals"],
        ).grid(row=5, column=0, columnspan=4, sticky="nsew", padx=10, pady=10, ipady=10)

        # Make grid scalable
        for i in range(4):
            root.grid_columnconfigure(i, weight=1)
        for i in range(6):
            root.grid_rowconfigure(i, weight=1)

    def make_button(self, text, row, col):
        if text in {"+", "-", "*", "/"}:
            bg = COLORS["operator"]
            fg = COLORS["bg"]
        elif text == "C":
            bg = COLORS["operator"]
            fg = COLORS["bg"]
        else:
            bg = COLORS["button"]
            fg = COLORS["button_text"]

        tk.Button(
            self.root,
            text=text,
            command=lambda t=text: self.on_press(t),
            bg=bg,
            fg=fg,
            font=("Consolas", 20),
            bd=0,
            activebackground=bg,
        ).grid(row=row, column=col, sticky="nsew", padx=10, pady=10, ipady=10)

    def on_press(self, char):
        if char == "C":
            self.expression = ""
        else:
            self.expression += str(char)
        self.display.delete(0, tk.END)
        self.display.insert(tk.END, self.expression)

    def calculate(self):
        try:
            result = str(eval(self.expression))
            self.display.delete(0, tk.END)
            self.display.insert(tk.END, result)
            self.expression = result
        except:
            self.display.delete(0, tk.END)
            self.display.insert(tk.END, "Error")
            self.expression = ""


if __name__ == "__main__":
    root = tk.Tk()
    Calculator(root)
    root.mainloop()
