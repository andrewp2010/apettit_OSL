# apettit OSL Library
apettit_OSL is a library of utility OSL shaders. The OSL source code can be compiled via oslc and should be viable in any renderer that supports osl (though it may require upadtes for parameter metadata). In addition this library provides the necessary scripts to convert compiled osl data into Side FX Houdini's native hda. The conversion scripts rely on Pixar Renderman's python library as a framework.

## Supported Platforms
----------------------
apettit_OSL is currently support on Windows platforms, and has been built and tested on Windows 10.

The OSL source code is not dependen on platform, but rather the renderer. It has been build and tested on Renderman 24.4. Given the nature of OSL it should be supported in other renderers but support should be considered experimental at this time.

I am actively working on porting apettit_OSL scrits to Linux. apettit_OSL script support should be considered experimental for Linux at this time.


## Dependencies
---------------
apettit_OSL was designed to be supported in SideFX Houdini through Pixar Renderman's framework. The required OSL dependencies are downloaded with a fresh install of Houdini. The following dependencies are recommended for the full support of apettit_OSL and its scripts:
 - [SideFX Houdini](https://www.sidefx.com/)
 - [Pixar's Renderman](https://renderman.pixar.com/)

 ### Optional
 If you just want to compile the osl source code the following dependencies are required:
 - [OSL](https://github.com/AcademySoftwareFoundation/OpenShadingLanguage.git)

 ### Tested Versions
| Software          | Version  |
| ----------------- |:--------:|
| SideFX Houdini    | 19.0.589 |
| Pixar's Renderman | 24.4-py3 |

 Any other versions are considered experimental at this time


## Getting and Building the Code
--------------------------------

### 1. Install Prerequisites (see [Dependencies](#dependencies) for required versions)
### 2. Download the apettit_OSL source code
You can download source code archives from [GitHub](https://github.com/andrewp2010/apettit_OSLlib) or use ```git``` to clone the repository.

```
> git clone https://github.com/andrewp2010/apettit_OSLlib
```

### 3. Set Required Environment Variables (see [Environment Variables](#Environment) for required versions)

#### System Environment Variables:
| Variable   | Path                                                                        |
| ---------- |-----------------------------------------------------------------------------|
| PATH       | <apettit_OSL dir>\scripts                                                   |
| HYTHONPATH | "C:\Program Files\Side Effects Software\Houdini 19.0.589\bin\hython3.7.exe" |

Note: if there are any spaces in your env var paths remember to place the path within "". This will commonly be the case for the HYTHONPATH

#### Houdini.env:
| Variable             | Path                     |
| -------------------- |--------------------------|
| HOUDINI_OTLSCAN_PATH | <apettit_OSL dir>\otls;& |
| RMAN_SHADERPATH      | <apettit_OSL dir>\bin;&  |

### 4. Compile OSL Source Code
```
> hython srcipts\oslBuild.py -l -c
```

### 5. Try it out
```
> oslTest
```

## Additional Information
-------------------------
### Scripts
#### Batch
Batch files that can be called anywhere in command prompt
- ```oslHome``` cd to apettit_OSL dir
- ```oslTest``` opens a sandbox houdini file to test compiled shaders
- ```hython``` command to use in place of ```python```, to use houdini python interpreter
#### Python
Python scripts to be called in apettit_OSL dir:
- ```oslBuild.py``` compile osl source code and place in ```bin```
- ```osl2hda.py``` converts oso code to houdini hda
- Note: can be run with ```-h``` for more help information and python scripts must be run with hython interpreter
```hython scripts\oslBuild.py -h```

### Environment
- ```PATH``` required to call custom batch files in windows command prompt
- ```HYTHONPATH``` custom variable for hython  batch command
- ```HOUDINI_OTLSCAN_PATH``` dir houdini looks at for osl lib (hda) at startup
- ```RMAN_SHADERPATH``` required for rfh.config.py to connect oso data to generated osl lib (hda)

### Visual Studio
For an optimal environemtn set the python interpreter to the HYTHONPATH
Can set this by default in settings.json:
```
"python.defaultInterpreterPath": "C:/Program Files/Side Effects Software/Houdini 19.0.589/bin/hython3.7.exe"
```

## License
----------
Apache License 2.0






	---------- OSL mtoa Environment Variables ----------
CUSTOM_GENERAL_OSL = C:\dev\Plugins\General\OSL
ARNOLD_PLUGIN_PATH = %CUSTOM_GENERAL_OSL%