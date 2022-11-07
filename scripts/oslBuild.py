import ap, argparse, copy, glob, os

def compile(renderer, shader):
    # format inputFile/outputFile to [dir, shaderName, file ext]
    input = []
    input.append("src")
    input.append(renderer)
    tmp = shader.split('.')
    input.append(tmp[0])
    input.append(tmp[1])

    output = copy.copy(input)
    output[0] = 'bin'
    output[3] = 'oso'

    inputFile = input[0] + '\\' + input[1] + '\\' + input[2] + '.' + input[3]
    outputFile = output[0] + '\\' + output[1] + '\\' + output[2] + '.' + output[3]

    # check for /bin dir
    if (os.path.isdir("bin") == False):
        ap.print.info("make bin")
        os.mkdir("bin")

    # check for /bin/<renderer> dir
    if (os.path.isdir("bin\\" + renderer) == False):
        ap.print.info("make bin\\" + renderer)
        os.mkdir("bin\\" + renderer)

    # output
    ap.print.info(renderer + ': ' + input[2])

    #compile osl and output
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
parser.add_argument("-c", "--convert", action = "store_true", help = "run osl2hda.py script following build")
args = parser.parse_args()

if (args.lib):
    # find src directory
    filePath = os.path.dirname(os.path.realpath(__file__))
    root, _ = os.path.split(filePath)
    srcDir = root + "\src"

    # get renderer and shader
    for renderer in os.listdir(srcDir):
        rendererDir = srcDir + "\\" + renderer
        for file in glob.glob(rendererDir + "\\*.osl"):
            _, shader = os.path.split(file)
            _, renderer = os.path.split(_)
            compile(renderer, shader)
else:
    # get renderer and shader
    _, shader = os.path.split(args.shader)
    _, renderer = os.path.split(_)
    compile(renderer, shader)

if (args.convert):
    exec(open("scripts\osl2hda.py").read())