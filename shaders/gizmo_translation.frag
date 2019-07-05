#version 430 compatibility
varying vec4 color;
uniform bool Hovered;

void main()
{
    if(Hovered)
        gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);
    else
        gl_FragColor = color;
}
