__kernel void test(__global int* data)
{
	int x = get_global_id(0);
 //   int y = get_global_id(1);
    data[x] = (255 << 16) + (255 << 8) + 255;
}