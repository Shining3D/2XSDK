#version 120
varying vec4 color;
varying vec2 TextCoord0;

uniform vec4 MaterialColor;

void main()
{
    color = MaterialColor;
    gl_Position = ftransform();
    TextCoord0 = gl_MultiTexCoord0.xy;
}
