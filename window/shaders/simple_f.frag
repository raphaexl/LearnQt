#version 330 core

in  vec4     v_color;
out vec4    frag_color;



vec2    m_compute(vec2 z, vec2 c)
{
    vec2   res;

    res.x = z.x * z.x - z.y * z.y + c.x;
    res.y = z.y * z.x + z.y * z.x + c.y;
    return (res);
}

vec4    m_color(int n, int n_max)
{
    int     r, g, b;
    int     nn;
    float   t;

    t = (1.0 * n) / (1.0f * n_max);
    n = int(t * (256 * 256 * 256));
    b = n / (256 * 256);
    nn = n - b * (256 * 256);
    r = nn / 256;
    g = nn - r * 256;
    return (vec4(r * (1.0f / 256.0f), g * (1.0f / 256.0f), b * (1.0f / 256.0f), 1.0f));
}

vec2    m_map(int x, int y)
{
    vec2    z;
    vec2    pmin, pmax;

    pmin.x = (0.0f - 800.0f / 2.0f) * 4.0f / 800.0f;
    pmin.y = (0.0f - 800.0f / 2.0f) * 4.0f / 800.0f;
    pmax.x = (800.0f - 800.0f / 2.0f) * 4.0f / 800.0f;
    pmax.y = (800.0f - 800.0f / 2.0f) * 4.0f / 800.0f;

    z.x = pmin.x + ((pmax.x - pmin.x) / 800.0f) * (1.0 * x);
    z.y = pmin.y + ((pmax.y - pmin.y) / 800.0f) * (1.0 * y);
    return (z);
}

void main(void)
{
   ivec2   uv = ivec2(gl_FragCoord.x, 800 - gl_FragCoord.y);

    vec2    z = m_map(uv.x, uv.y);
    vec2    c = z;
    int i = 0;
    for (i = 0; (z.x * z.x + z.y * z.y) < 4.0 && i < 100; i++)
        z = m_compute(z, c);
    if (i == 100)
        frag_color = v_color;
    else
        frag_color = m_color(i, 100);
    //frag_color = v_color;
}
