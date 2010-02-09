#ifndef SNMPUDPBASEDOMAIN_H
#define SNMPUDPBASEDOMAIN_H

#ifdef __cplusplus
extern          "C" {
#endif

/*
 * Prototypes
 */
    void _netsnmp_udp_sockopt_set(int fd, int local);
    int netsnmp_udpbase_close(netsnmp_transport *t);
    netsnmp_transport *netsnmp_udpbase_transport(struct sockaddr_in *addr,
                                                 int local);

#endif /* SNMPUDPBASEDOMAIN_H */
