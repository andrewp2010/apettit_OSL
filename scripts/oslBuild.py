import ap, argparse, copy, glob, os

def compile(shader):
    # format inputFile/outputFile to [dir, shaderName, file ext]
    input = []
    input.append("src")
    tmp = shader.split('.')
    input.append(tmp[0])
    input.append(tmp[1])

    output = copy.copy(input)
    output[0] = 'bin'
    output[2] = 'oso'

    inputFile = input[0] + '\\' + input[1] + '.' + input[2]
    outputFile = output[0] + '\\' + output[1] + '.' + output[2]

    # check for /bin dir
    if (os.path.isdir("bin") == False):
        ap.print.info("make /bin")
        os.mkdir("bin")

    # output
    print(input[1])

    cmd = 'cmd /c "oslc %s -o %s"' % (inputFile, outputFile)
    process = os.popen(cmd)
    processLog = process.read()
    process.close()

    if ("FAILED" in processLog):
        ap.print.error(processLog)
    else:
        ap.print.success(processLog)

parser = argparse.ArgumentParser(
                                 description = "Compile a single apettit OSL " 
                                               "shader or the entire apettit "
                                               "OSL library"
                                )
g = parser.add_mutually_exclusive_group()

g.add_argument("-s", "--shader", help = "Shader file to compile")
g.add_argument("-l", "--lib", action='store_true', help = "Compile apettit shader library")

args = parser.parse_args()

filePath = os.path.dirname(os.path.realpath(__file__))
root, _ = os.path.split(filePath)

if (args.lib):
    for file in glob.glob(root + "\src\*.osl"):
        _, shader = os.path.split(file)
        compile(shader)
else:
    _, shader = os.path.split(args.shader)
    compile(shader)