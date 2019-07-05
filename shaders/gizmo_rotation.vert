#version 410 compatibility
//uniform mat4 osg_ModelViewProjectionMatrix;
out vec4 color;
out vec4 centerPos;
out vec4 vertexPos;

void main()
{
    color = gl_Color;
    vec4 center = vec4(0, 0, 0, 1);
    centerPos = osg_ModelViewProjectionMatrix * center;
    vertexPos = ftransform();
    gl_Position = vertexPos;
}
