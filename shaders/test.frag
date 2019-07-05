#version 430 compatibility
in vec4 color;
in vec4 centerPos;
in vec4 vertexPos;

void main()
{
    if(vertexPos.z > centerPos.z)
        discard;
    else
        gl_FragColor = color;
}
