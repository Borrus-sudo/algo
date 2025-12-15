def to_base(n, base):
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if n == 0:
        return "0"
    result = ""
    while n > 0:
        result = digits[n % base] + result
        n //= base
    return result


def convert_base(num_str, from_base, to_base_):
    decimal_value = int(num_str, from_base)
    return to_base(decimal_value, to_base_)


print(convert_base("101101", 2, 16))
print(convert_base("2D", 16, 2))
print(convert_base("123", 4, 9))
