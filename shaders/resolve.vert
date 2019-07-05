#version 430 compatibility
varying vec2 texCoord;
void main()
{
 texCoord = gl_MultiTexCoord0.xy;
 gl_Position = vec4(2*texCoord.x-1, 2*texCoord.y-1, 0.1, 1.0); // arbitrary depth as depth test alwarys pass
}