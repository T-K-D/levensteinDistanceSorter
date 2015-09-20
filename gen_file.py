import string
import random

def string_generator():
    size=random.randint(100, 200)
    chars=string.ascii_letters + string.digits
    return ''.join(random.choice(chars) for _ in range(size))


def gen_file(length=1000):
    with open("strings.gen", 'w+') as outfile:
        for i in range(1000):
            outfile.write(string_generator() + "\n")


gen_file()
