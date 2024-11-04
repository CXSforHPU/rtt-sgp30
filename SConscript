from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()
src += Glob('src/sgp30.c')

if GetDepend('PKG_USING_SGP30_SAMPLE'):
    src += Glob('examples/sgp30_sample.c')

# add sgp30 src files.
if GetDepend('PKG_SGP30_USING_SENSOR_V1'):
    src += Glob('src/sgp30_sensor_v1.c')

if GetDepend("PKG_SGP30_USING_SENSOR_V1_SAMPLE"):
    src += Glob('examples/sgp30_sample_sensor_v1.c')
    src += Glob('examples/sgp30_cmd_sample_sensor_v1.c')

# add sgp30 include path.
path  = [cwd + '/inc']

# add src and include to group.
group = DefineGroup('sgp30', src, depend = ['PKG_USING_SGP30'], CPPPATH = path)

Return('group')