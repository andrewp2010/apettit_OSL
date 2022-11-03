# GeneralPlugins
General Plugins

---------- OSL mtoa Environment Variables ----------
CUSTOM_GENERAL_OSL = C:\dev\Plugins\General\OSL
ARNOLD_PLUGIN_PATH = %CUSTOM_GENERAL_OSL%


Auto load OSL pipeline scripts here:
    C:\Users\andre\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1




change houdini ui color on OSL-ENV type
streamline UI

Environment Variables
	- PATH = C:\dev\Plugins\General\OSL\scripts
		- apettit OSL directory
	- HYTHONPATH = "C:\Program Files\Side Effects Software\Houdini 19.0.589\bin\hython3.7.exe"
		- windows: if there are spaces in HYTHONPATH make sure to enclos path in "" or the hython batch file will fail

houdini.env
	- HOUDINI_OTLSCAN_PATH = C:/dev/Plugins/General/OSL/otls;&
		- dir houdini looks for hda

visual studio
	- set python interpreter to Hython file
	- settings.json
	    - "python.defaultInterpreterPath": "C:/Program Files/Side Effects Software/Houdini 19.0.589/bin/hython3.7.exe"