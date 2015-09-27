import string
import random

def string_generator():
    size=random.randint(500, 1000)
    chars=string.ascii_letters + string.digits
    return ''.join(random.choice(chars) for _ in range(size))


def gen_file(length=1000):
    with open("strings.gen", 'w+') as outfile:
        for i in range(25000):
            outfile.write(string_generator() + "\n")


gen_file()
