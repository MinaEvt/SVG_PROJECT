
#Vseh go ot internet
import os

# Create the build environment
env = Environment()

# Get all .cpp files in the current directory and subdirectories
def collect_cpp_files(root):
    cpp_files = []
    for dirpath, _, filenames in os.walk(root):
        for filename in filenames:
            if filename.endswith('.cpp'):
                cpp_files.append(os.path.join(dirpath, filename))
    return cpp_files

# Collect all CPP files in the src directory
cpp_files = collect_cpp_files("./")
# Specify the target executable and its source files
env.Program(target='main', source=cpp_files)