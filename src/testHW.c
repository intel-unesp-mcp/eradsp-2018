#include <stdint.h>
#include <stdio.h>

#pragma omp declare target
void what_cpu()
{
    uint32_t eax;
    const uint32_t xeon_phi_x100_id = 0x00010;
    const uint32_t xeon_phi_x200_id = 0x50070;

    __asm volatile("cpuid":"=a"(eax):"a"(1));

    uint32_t this_cpu_id = eax & 0xF00F0;

    if (this_cpu_id == xeon_phi_x100_id)
        printf("This CPU is Intel(R) XeonPhi(TM) x100 Processor!\n");
    else
    if (this_cpu_id == xeon_phi_x200_id)
        printf("This CPU is Intel(R) XeonPhi(TM) x200 Processor!\n");
    else
        printf("This CPU is other Intel(R) Processor.\n");
}

int main()
{
    char hostname[1024];
    printf("Running on host: ");
    gethostname(hostname, 1024);
    puts(hostname);
    what_cpu();

    #pragma omp target
    {
        printf("Running on target: ");
        gethostname(hostname, 1024);
        puts(hostname);
        what_cpu();
    }

    return 0;
}
