import os
import filecmp

#pwd = os.path.dirname(os.path.realpath(__file__))
pwd = ""

#defining vars
default_flags = "-std=c++11 -S -O"
run_gcc_base = ["gcc", default_flags]
check_dir = pwd + "opt-check/"
src = ["src/LevenshteinCalculator.cpp"]

#compiling testing .o file
if not os.path.exists(check_dir):
    os.makedirs(check_dir, 777)

test_filename = check_dir + "test.o"
os.system(" ".join(run_gcc_base) + " " + " ".join(src) + " -o " + test_filename)

#creating output file
output = open(check_dir + "USEFULL_FLAGS.txt", "w+")

all_flags = 0
used_flags = 0
#read flags file
with open("options.txt", "r+") as f:
    for line in f:
        opt = line.replace('\n', '').strip()
        if len(opt) > 0:
            all_flags += 1
            filename = check_dir + opt[2:] + ".o"

            print(" >>> Processing " + filename)

            #compile files
            os.system(" ".join(run_gcc_base) + " " + opt + " " + " ".join(src) + " -o " + filename)

            #compare file with start version
            if not filecmp.cmp(test_filename, filename):
                #if files are not equal then do =>
                used_flags += 1
                output.write(opt + "\n")
                diff_run = ["diff", test_filename, filename, ">", filename + ".diff"]
                os.system(" ".join(diff_run))

output.close()
print("  ====> FINISHED! {0} of {1} flags made some noise.".format(used_flags, all_flags))
