#include <linux/bpf.h>

#define PORT 4040 

SEC("classifier")
int xdp_prog(struct xdp_md *ctx)
{
    void *data = (void *)(long)ctx->data;
    void *data_end = (void *)(long)(ctx->data + ctx->data_len);
    struct ethhdr *eth = data;
    struct ip *ip;

    if (eth->h_proto != ETH_P_IP)
    {
        return XDP_PASS;
    }

    ip = data + sizeof(struct ethhdr);

    if (ip->ip_p != IPPROTO_TCP)
    {
        return XDP_PASS;
    }

    struct tcphdr *tcp;
    if (data + sizeof(struct ethhdr) + sizeof(struct ip) > data_end)
    {
        return XDP_PASS;
    }
    tcp = data + sizeof(struct ethhdr) + sizeof(struct ip);

    if (tcp->dest != htons(PORT))
    {
        return XDP_PASS;
    }

    return XDP_DROP;
}

char _license[] SEC("license") = "GPL";
`