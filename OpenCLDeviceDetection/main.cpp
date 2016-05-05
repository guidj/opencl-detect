

#include <stdio.h>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include <iostream>
using namespace std;

string device_type_name(cl_device_type device_type) {
	string type;
	switch(device_type){
		case CL_DEVICE_TYPE_CPU:
			type = "CPU";
			break;
		case CL_DEVICE_TYPE_GPU:
			type = "GPU";
			break;
		case CL_DEVICE_TYPE_ACCELERATOR:
			type = "Accelerator";
			break;
		case CL_DEVICE_TYPE_DEFAULT:
			type = "Default";
		default:
			type = "Unknown";
	}

	return type;
}

int main(int argc, char** argv)
{
    char dname[500];
    cl_uint num_devices;
    cl_device_id devices[10];

    size_t namesize;
    int d;

    // 1. Get a platform.
    cl_platform_id platform;
    clGetPlatformIDs( 1, &platform, NULL );

    clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 10, devices, &num_devices);
    printf("%d devices found\n\n", num_devices);

    for (d = 0; d < num_devices; ++d) {

        clGetDeviceInfo(devices[d], CL_DEVICE_NAME, 500, dname, &namesize);
        printf("Device #%d name = %s\n", d, dname);

        cl_device_type device_type;
        clGetDeviceInfo(devices[d], CL_DEVICE_TYPE, sizeof(cl_device_type),
                        &device_type, NULL);
        cout << "device type = " << device_type_name(device_type) << endl;

        cl_uint num_cores;
        clGetDeviceInfo(devices[d], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint),
                        &num_cores, NULL);
        cout << "num cores = " << num_cores << endl;

        cl_uint address_bits;
        clGetDeviceInfo(devices[d], CL_DEVICE_ADDRESS_BITS, sizeof(cl_uint),
                        &address_bits, NULL);
        cout << "num addr bit = " << address_bits << endl;

        cl_bool  avail;
        clGetDeviceInfo(devices[d], CL_DEVICE_AVAILABLE, sizeof(cl_bool),
                        &avail, NULL);
        cout << "availability = " << address_bits << endl;

        cl_ulong global_mem_cache_size;
        clGetDeviceInfo(devices[d], CL_DEVICE_GLOBAL_MEM_CACHE_SIZE,
                        sizeof(cl_ulong), &global_mem_cache_size, NULL);
        cout << "global mem cache size = " << global_mem_cache_size << endl;

        cl_uint global_mem_cacheline_size;
        clGetDeviceInfo(devices[d], CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE,
                        sizeof(cl_uint), &global_mem_cacheline_size, NULL);
        cout << "global mem cacheline size = " << global_mem_cache_size << endl;

        cl_ulong global_mem_size;
        clGetDeviceInfo(devices[d], CL_DEVICE_GLOBAL_MEM_SIZE ,
                        sizeof(cl_ulong), &global_mem_size, NULL);
        cout << "global mem size = " << global_mem_size << endl;

        size_t image2d_hgt;
        clGetDeviceInfo(devices[d], CL_DEVICE_IMAGE2D_MAX_HEIGHT,
                        sizeof(size_t), &image2d_hgt, NULL);
        cout << "image2d height = " << image2d_hgt << endl;

        size_t image2d_width;
        clGetDeviceInfo(devices[d], CL_DEVICE_IMAGE2D_MAX_WIDTH,
                        sizeof(size_t), &image2d_width, NULL);
        cout << "image2d width = " << image2d_width << endl;


        size_t image3d_depth;
        clGetDeviceInfo(devices[d], CL_DEVICE_IMAGE3D_MAX_DEPTH,
                        sizeof(size_t), &image3d_depth, NULL);
        cout << "image3d depth = " << image3d_depth << endl;

        size_t image3d_height;
        clGetDeviceInfo(devices[d], CL_DEVICE_IMAGE3D_MAX_HEIGHT,
                        sizeof(size_t), &image3d_height, NULL);
        cout << "image3d height = " << image3d_height << endl;

        size_t image3d_width;
        clGetDeviceInfo(devices[d], CL_DEVICE_IMAGE3D_MAX_WIDTH,
                        sizeof(size_t), &image3d_width, NULL);
        cout << "image3d width = " << image3d_width << endl;

        size_t localmem_size;
        clGetDeviceInfo(devices[d], CL_DEVICE_LOCAL_MEM_SIZE,
                        sizeof(size_t), &localmem_size, NULL);
        cout << "localmem size = " << localmem_size << endl;

        size_t max_clock_freq;
        clGetDeviceInfo(devices[d], CL_DEVICE_MAX_CLOCK_FREQUENCY,
                        sizeof(size_t), &max_clock_freq, NULL);
        cout << "max clock freq = " << max_clock_freq << endl;

        size_t max_compute_units;
        clGetDeviceInfo(devices[d], CL_DEVICE_MAX_COMPUTE_UNITS,
                        sizeof(size_t), &max_compute_units, NULL);
        cout << "max compute units = " << max_compute_units << endl;

        cl_ulong max_constant_buff_size;
        clGetDeviceInfo(devices[d], CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE,
                        sizeof(cl_ulong), &max_constant_buff_size, NULL);
        cout << "max constant buff size = " << max_constant_buff_size << endl;

        size_t max_work_group_size;
        clGetDeviceInfo(devices[d], CL_DEVICE_MAX_WORK_GROUP_SIZE,
                        sizeof(size_t), &max_work_group_size, NULL);
        cout << "max work group size = " << max_work_group_size << endl;

        clGetDeviceInfo(devices[d], CL_DRIVER_VERSION, 500, dname, &namesize);
        cout << "OpenCL version: " << dname << endl;

        cout << endl;
    }

    return 0;
}
