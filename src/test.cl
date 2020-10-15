__kernel void test(__global int* pixels)
{
	int x = get_global_id(0);
    int y = get_global_id(1);
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < 10)
    {
        i = 0;
        while (i < 100)
        {
            j = 0;
            while (j < 100)
            {
                pixels[i * 640 + j] = 0xff0000;
                j++;
            }
            i++;
        }
        i = 100;
        while (i < 200)
        {
            j = 0;
            while (j < 100)
            {
                pixels[i * 640 + j] = 0xfff000;
                j++;
            }
            i++;
        }
        k++;
    }
}