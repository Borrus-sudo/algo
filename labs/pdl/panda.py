import pandas as pd

print("\n=== 1. CREATE DATAFRAME ===")
data = {"Name": ["Alice", "Bob", "Charlie"], "Age": [24, 30, 29], "Score": [88, 92, 95]}
df = pd.DataFrame(data)
print(df)


print("\n=== 3. ACCESS ROWS & COLUMNS ===")
print("Age column:\n", df["Age"])
print("Name & Score:\n", df[["Name", "Score"]])
print("Row with loc:\n", df.loc[1])
print("Row with iloc:\n", df.iloc[1])
print("Cell [1,'Score']:", df.loc[1, "Score"])


print("\n=== 4. FILTERING ===")
adults = df[df["Age"] >= 25]
print("Adults:\n", adults)

res = df[(df["Age"] > 25) & (df["Score"] > 90)]
print("Age >25 and Score >90:\n", res)


print("\n=== 5. ADD / UPDATE / DELETE COLUMNS ===")
df["Passed"] = df["Score"] > 90
print(df)

df["Age"] = df["Age"] + 1
print("Updated age:\n", df)

df = df.drop(columns=["Passed"])
print("After drop:\n", df)


print("\n=== 6. ADD / UPDATE / DELETE ROWS ===")
df.loc[len(df)] = ["David", 22, 85]  # add row
df.loc[1, "Age"] = 35  # update row
df = df.drop(0)  # delete row
print(df)


print("\n=== 7. SORTING ===")
df_sorted = df.sort_values("Score", ascending=False)
print(df_sorted)


print("\n=== 8. STATISTICS ===")
print("Describe:\n", df.describe())
print("Mean score:", df["Score"].mean())
print("Median age:", df["Age"].median())


print("\n=== 9. GROUPBY ===")
grouped = df.groupby("Age")["Score"].mean()
print(grouped)


print("\n=== 10. APPLY FUNCTION ===")
df["Category"] = df["Score"].apply(lambda x: "High" if x > 90 else "Low")
print(df)


print("\n=== 11. MERGE / JOIN ===")
df1 = pd.DataFrame({"ID": [1, 2], "Name": ["Alice", "Bob"]})
df2 = pd.DataFrame({"ID": [1, 2], "Score": [88, 92]})
merged = pd.merge(df1, df2, on="ID")
print(merged)


print("\n=== 12. MISSING VALUES ===")
messy = pd.DataFrame({"A": [1, None, 3], "B": [None, 5, 6]})
print("Original:\n", messy)

print("Fillna 0:\n", messy.fillna(0))
print("Dropna:\n", messy.dropna())
print("Fill column mean:\n", messy["A"].fillna(messy["A"].mean()))
