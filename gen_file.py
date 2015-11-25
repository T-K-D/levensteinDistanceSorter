import string
import random
import sys

def string_generator(word_len=1000):
    size=random.randint(500, word_len)
    chars=string.ascii_letters + string.digits
    return ''.join(random.choice(chars) for _ in range(size))


def gen_file(length=25000, word_len=1000):
    with open("strings.gen", 'w+') as outfile:
        for i in range(length):
            outfile.write(string_generator() + "\n")


if len(sys.argv) > 3:
    gen_file(int(sys.argv[1]), int(sys.argv[2]))
elif len(sys.argv) > 2:
    gen_file(int(sys.argv[1]))
else:
    gen_file()
