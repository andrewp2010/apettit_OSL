# GeneralPlugins
General Plugins

---------- OSL mtoa Environment Variables ----------
CUSTOM_GENERAL_OSL = C:\dev\Plugins\General\OSL
ARNOLD_PLUGIN_PATH = %CUSTOM_GENERAL_OSL%

---------- OSL rfh Environment Variables ----------

Environment Variables
	- PATH = C:\dev\Plugins\General\OSL\scripts
		- apettit OSL directory
	- HYTHONPATH = "C:\Program Files\Side Effects Software\Houdini 19.0.589\bin\hython3.7.exe"
		- windows: if there are spaces in HYTHONPATH make sure to enclos path in "" or the hython batch file will fail

houdini.env
	- HOUDINI_OTLSCAN_PATH = C:/dev/Plugins/General/OSL/otls;&
		- dir houdini looks for osl lib (hda) at startup
	- RMAN_SHADERPATH = C:/dev/Plugins/General/OSL/bin;&
		- required for rfh.config.py to connect oso data to generated osl lib

visual studio
	- set python interpreter to Hython file
	- settings.json
	    - "python.defaultInterpreterPath": "C:/Program Files/Side Effects Software/Houdini 19.0.589/bin/hython3.7.exe"