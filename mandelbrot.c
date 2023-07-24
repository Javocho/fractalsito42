#include "include/fractol.h"

void    maldelbrot(t_cplane *cp)
{
    int x;
    int y;
    double value;

    x = 0;
    while (x < cp->img_ptr->w)
    {
        y = 0;
        while(y < cp->img_ptr->h)
        {
            value = (double)is_not_stable(get_complex(x, y, cp), get_complex(x, y, cp), cp);
            if (value > 2)
            {
                put_pixel_img(cp->img_ptr, x, y, gen_trgb(0, 255 * (value / cp->iter), 40, 40))
            }
            ++y;
        }
        ++x;
    }
}

int is_not_stable(t_complex znum, t_complex cnum, int iter)
{
    t_complex tmp;
    int i;
    while (i++ < iter)
    {
        tmp = iplus(ipow(znum) + cnum);
        if (normal(tmp) > 2)
            return (i);
    }
    return (0);
}

t_complex get_complex(int x, int y, t_cplane *plane)
{
    t_complex num;
    num.creal = (x * plane->x_gap) + plane->x_s;
    num.cimagin = (y * plane->y_gap) + plane->y_s;
    return (num);
}