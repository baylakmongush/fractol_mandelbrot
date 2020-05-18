__kernel void test(__global int* data)
{
	int x = get_global_id(0);
    int y = get_global_id(1);
    int i = 0;
    int j = 0;

    while (i < 100)
    {
        j = 0;
        while (j < 100)
        {
         data[i * 800 + j] = 0x000000;
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
         data[i * 800 + j] = 0xffffff;
        j++;
        }
        i++;
    }
}