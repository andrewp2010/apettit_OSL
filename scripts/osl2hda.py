import ap, os, platform, rfh

# check for /bin dir
if (os.path.isdir("bin") == False):
    ap.print.info("make /bin")
    os.mkdir("bin")

shaderPaths = ["bin"]
libName = 'APETTIT_OSL_LIB'
otlLibFile = "otls/" + libName + ".hda"
iconPath = "src/icon/apettit_icon.png"

# remove old lib hda
if (os.path.exists(otlLibFile)):
    print("remove old APETTIT_OSL_LIB inst")
    os.remove(otlLibFile)

envs = ['RMAN_SHADERPATH']

for env in envs:
    try:
        envpath = os.environ.get(env)
        if envpath:
            if platform.system() == 'Windows':
                shaderpaths = envpath.split(';')
            else:
                shaderpaths = envpath.split(':')
            processLog = rfh.convertutils.main(shaderPaths,
                                               otlfile = otlLibFile,
                                               icon = iconPath,
                                               menu = "apettit",
                                            originalCase = True)
    except:
        ap.print.error("RFH: Could not register %s" % otlLibFile)

# output
if(processLog == None):
    ap.print.success(("SUCCESSFULLY converted %s:" % libName))
    ap.print.info(("otls/%s.hda" % libName))