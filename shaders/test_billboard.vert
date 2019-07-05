#version 430 compatibility
uniform mat4 osg_ModelViewMatrix;
uniform mat4 osg_ProjectionMatrix;
varying vec4 color;
varying vec4 centerPos;
void main()
{
    color = gl_Color;
    mat4 modelView = osg_ModelViewMatrix;
    modelView[0][0] = 1.0;
    modelView[0][1] = 0.0;
    modelView[0][2] = 0.0;

    modelView[1][0] = 0.0;
    modelView[1][1] = 1.0;
    modelView[1][2] = 0.0;

    modelView[2][0] = 0.0;
    modelView[2][1] = 0.0;
    modelView[2][2] = 1.0;

    vec4 P = modelView * gl_Vertex;
    gl_Position = osg_ProjectionMatrix * P;
}
