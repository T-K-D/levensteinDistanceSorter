import os
import filecmp

#pwd = os.path.dirname(os.path.realpath(__file__))
pwd = ""

#defining vars
default_flags = "-std=c++11 -S"
run_gcc_base = ["gcc", default_flags]
check_dir = pwd + "opt-check/"
src = ["src/LevenshteinCalculator.cpp"]
all_flags = 0
used_flags = 0

#checking output directory
if not os.path.exists(check_dir):
    os.makedirs(check_dir, 777)

#creating output file
output = open(check_dir + "USEFULL_FLAGS.txt", "w+")

#compiling testing .o file
test_filename = check_dir + "test.o"
compile_test_run = run_gcc_base + src + ["-o", test_filename]
os.system(" ".join(compile_test_run))

#read flags file
with open("options.txt", "r+") as f:
    for line in f:
        opt = line.replace('\n', '').strip()
        if len(opt) > 0:
            all_flags += 1
            filename = check_dir + opt[2:] + ".o"

            print(" >>> Processing " + filename)

            #compile files
            compile_opt_run = run_gcc_base + [opt] + src +  ["-o", filename]
            os.system(" ".join(compile_opt_run))

            #compare file with start version
            if not filecmp.cmp(test_filename, filename):
                #if files are not equal then do =>
                used_flags += 1
                output.write(opt + "\n")
                diff_run = ["diff", test_filename, filename, ">", filename + ".diff"]
                os.system(" ".join(diff_run))
            else:
                #remove uninteresting file
                rm_run = ["rm", "-f", filename]
                os.system(" ".join(rm_run))

output.close()
print("  ====> FINISHED! {0} of {1} flags made some noise.".format(used_flags, all_flags))
