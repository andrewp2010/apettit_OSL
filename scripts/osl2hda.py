import logging, os, rfh

filePath = os.path.dirname(os.path.realpath(__file__))
root, _ = os.path.split(filePath)

root = root.replace(os.sep, '/')

shaderPaths = [(root + "/bin")]
libName = 'APETTIT_OSL_LIB'
otlLibFile = root + "/otls/" + libName + ".hda"
iconPath = root + "/src/icon/apettit_icon.png"

if (os.path.exists(otlLibFile)):
    os.remove(otlLibFile)

rfh.convertutils.main(shaderPaths,
                        otlfile = otlLibFile,
                        icon = iconPath,
                        menu = "apettit",
                        originalCase = True)