import ap, os, platform, rfh

# check for /bin dir
if (os.path.isdir("bin") == False):
    ap.print.info("no /bin compile osl shaders with oslBuild.py")
    os.mkdir("bin")

for renderer in os.listdir("bin"):
    # get renderer specific parameters
    rendererPaths = [] # convertutils -> renderPaths is expecting an array
    rendererPaths.append("bin/" + renderer)
    libName = "APETTIT_OSL_"
    otlLibFile = "otls/" + libName + renderer.upper() + ".hda"

    # remove old hda
    if (os.path.exists(otlLibFile)):
        print("remove outdated %s" % otlLibFile)
        os.remove(otlLibFile)

    # convert method
    processLog = rfh.convertutils.main(rendererPaths,
                                       otlfile = otlLibFile,
                                       icon = "icon/apettit_icon.png",
                                       menu = "apettit",
                                       namespace = "apettit",
                                       originalCase = True)

    # output
    if(processLog == None):
        ap.print.success(("SUCCESSFULLY converted %s:" % (libName + renderer)))
        ap.print.info((otlLibFile + '\n'))

