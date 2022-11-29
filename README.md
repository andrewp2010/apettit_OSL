# apettit OSL Library
apettit_OSL is a library of utility OSL shaders. The OSL source code can be compiled via oslc and should be viable in any renderer that supports osl (though it may require updates for parameter metadata dependent on the renderer). In addition this library provides the necessary scripts to convert compiled osl data into Side FX Houdini's native hda. The conversion scripts rely on Pixar Renderman's python library as a framework.

Conversion scripts are designed to allow users to add their own custom OSL source code as well.

See [OSL Documentation](osl-languagespec.pdf) for more information on OSL syntax

## Supported Platforms
apettit_OSL is currently supported on Windows platforms, and has been built and tested on Windows 10.

The OSL code is not dependent on platform, but rather the renderer. It has been build and tested on Renderman 24.4. Given the nature of OSL it should be supported in other renderers but support should be considered experimental at this time. 
OSL shaders are relatively dependent upon the OSL shader. See [Library Structure](#library-structure) for more in depth explanation.


I am actively working on porting apettit_OSL scripts to Linux. apettit_OSL script support should be considered experimental for Linux at this time.


## Dependencies
apettit_OSL was designed to be supported in SideFX Houdini through Pixar Renderman's python library.The following dependencies are required for the full support of apettit_OSL and its scripts:
 - [SideFX Houdini](https://www.sidefx.com/)
 - [Pixar's Renderman](https://renderman.pixar.com/)

 Any other required OSL dependencies are downloaded with Houdini and Renderman. 

 ### Optional
 If you just want to compile the osl code, and do not wish to use apettit_OSL custom scripts, then only following dependencies are required:
 - [OSL](https://github.com/AcademySoftwareFoundation/OpenShadingLanguage.git)

 ### Tested Versions
| Software          | Version  |
| ----------------- |:--------:|
| SideFX Houdini    | 19.0.589 |
| Pixar's Renderman | 24.4-py3 |

 Any other versions are considered experimental at this time


## Getting and Building the Code

### 1. Install Prerequisites (see [Dependencies](#dependencies))

### 2. Download the apettit_OSL source code
You can download source code from [GitHub](https://github.com/andrewp2010/apettit_OSLlib) or use ```git``` to clone the repository.

```
> git clone https://github.com/andrewp2010/apettit_OSLlib
```

### 3. Set Required Environment Variables (see [Environment](#Environment) for additional info)

#### System Environment Variables:
| Variable   | Path                                                                        |
| ---------- |-----------------------------------------------------------------------------|
| PATH       | <apettit_OSL dir>\scripts                                                   |
| HYTHONPATH | "C:\Program Files\Side Effects Software\Houdini 19.0.589\bin\hython3.7.exe" |

Note: if there are any spaces in your environment variable paths remember to place the path within "". This will commonly be the case for the HYTHONPATH on windows

#### Houdini.env:
| Variable             | Path                               |
| -------------------- | ---------------------------------- |
| HOUDINI_OTLSCAN_PATH | <apettit_OSL dir>\otls;&           |
| RMAN_SHADERPATH      | <apettit_OSL dir>\bin\general;&    |
| RMAN_SHADERPATH      | <apettit_OSL dir>\bin\renderman;&  |

Note: see [Library Structure](#library-structure) for RMAN_SHADERPATH logic

### 4. Compile OSL Source Code
```
> hython srcipts\oslBuild.py -l -c
```

### 5. Try it out
```
> oslTest
```

## Additional Information

### Library Structure
This OSL library supports shaders that are renderer specific and generally supported (whether they are supported generally or not is dependent on whether the shdaer contains any metadata specific to any given renderer).
Where shaders are placed in the ```src``` is important for this reason. Renderer specific shaders should be placed within a folder that is specific to the renderer, e.g. ```src\renderman``` (the user can add any number of folders they desire). General shaders can be placed in ```src\general```. At compile time the ```osl2hda.py``` will create different library files dependent upon folders within ```src```. Therefore, renderers will generally need an environment variable that points to both the general and their renderer specific bin folder. This is why ```RMAN_SHADERPATH``` requires two paths in the [setup above](#houdinienv).

### Namespace and Versioning
All general versioning and namespace practices apply to this library.
The ```oslBuild.py``` script recognizes specific parameters for versioning and namespace. By default the namespace for all shaders compiled using ```oslBuild.py``` will be ```apettit```. If you would like to change that you will have to change the namespace parameter within the script. The shader version is decided by the number following the shaders filename: ```apColor_1.osl```. By default houdini will only provide the option for the most recent version of a shader, unless a file is already referencing an older version, then it will provide reference to the version in the file and the most recent version.

### Scripts

#### Batch
Batch files that can be called anywhere in command prompt
- ```oslHome``` cd to apettit_OSL dir
- ```oslTest``` opens a sandbox houdini file to test compiled shaders
- ```hython``` command to use in place of ```python```, to use houdini python interpreter

#### Python
Python scripts to be called in apettit_OSL dir:
- ```oslBuild.py``` compile osl source code and place in ```bin```
- ```osl2hda.py``` converts compiled osl code to houdini hda
- Note: can be run with ```-h``` for more help information and python scripts must be run with hython interpreter, e.g.
```hython scripts\oslBuild.py -h```

### Environment
- ```PATH``` required to call custom batch files in windows command prompt
- ```HYTHONPATH``` custom variable for hython  batch command
- ```HOUDINI_OTLSCAN_PATH``` dir houdini looks at for osl hda at startup
- ```RMAN_SHADERPATH``` required for rfh.config.py to connect compiled osl data to generated osl hda

### Visual Studio
For an optimal environment set the python interpreter to the HYTHONPATH
Can set this to be startup default in settings.json:
```
"python.defaultInterpreterPath": "C:/Program Files/Side Effects Software/Houdini 19.0.589/bin/hython3.7.exe"
```

## License
Apache License 2.0

## misc
Future environment variables for Arnold support
- CUSTOM_GENERAL_OSL = C:\dev\Plugins\General\OSL
- ARNOLD_PLUGIN_PATH = %CUSTOM_GENERAL_OSL%