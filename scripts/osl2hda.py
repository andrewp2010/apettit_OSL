import ap, os, rfh

filePath = os.path.dirname(os.path.realpath(__file__))
root, _ = os.path.split(filePath)

root = root.replace(os.sep, '/')

# check for /bin dir
if (os.path.isdir("bin") == False):
    ap.print.info("make /bin")
    os.mkdir("bin")

shaderPaths = [(root + "/bin")]
libName = 'APETTIT_OSL_LIB'
otlLibFile = root + "/otls/" + libName + ".hda"
iconPath = root + "/src/icon/apettit_icon.png"

# remove old lib instance
if (os.path.exists(otlLibFile)):
    print("remove old APETTIT_OSL_LIB inst")
    os.remove(otlLibFile)

processLog = rfh.convertutils.main(shaderPaths,
                        otlfile = otlLibFile,
                        icon = iconPath,
                        menu = "apettit",
                        originalCase = True)

# output
if(processLog == None):
    ap.print.success(("SUCCESSFULLY converted %s:" % libName))
    ap.print.info(("otls/%s.hda" % libName))