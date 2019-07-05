#version 410 compatibility
in vec4 color;
in vec4 centerPos;
in vec4 vertexPos;
uniform bool Hovered;

void main()
{
    if(vertexPos.z > centerPos.z)
        discard;
    else{
        if(Hovered)
            gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);
        else
            gl_FragColor = color;
    }

}
