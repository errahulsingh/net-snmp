/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.int_watch.conf,v 5.0 2002/04/20 07:30:13 hardaker Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "nstAgentPluginObject.h"

/*
 * the variable we want to tie an OID to.  The agent will handle all
 * * GET and SET requests to this variable changing it's value as needed.
 */

static int      nstAgentPluginObject = 3;

/*
 * our initialization routine, automatically called by the agent 
 * (to get called, the function name must match init_FILENAME()) 
 */
void
init_nstAgentPluginObject(void)
{
    static oid      nstAgentPluginObject_oid[] =
        { 1, 3, 6, 1, 4, 1, 8072, 2, 4, 1, 1, 3, 0 };

    /*
     * a debugging statement.  Run the agent with -DnstAgentPluginObject to see
     * the output of this debugging statement. 
     */
    DEBUGMSGTL(("nstAgentPluginObject",
                "Initializing the nstAgentPluginObject module\n"));


    /*
     * the line below registers our variables defined above as
     * accessible and makes it writable.  A read only version of any
     * of these registration would merely call
     * register_read_only_int_instance() instead.  The functions
     * called below should be consistent with your MIB, however.
     * 
     * If we wanted a callback when the value was retrieved or set
     * (even though the details of doing this are handled for you),
     * you could change the NULL pointer below to a valid handler
     * function. 
     */
    DEBUGMSGTL(("nstAgentPluginObject",
                "Initalizing nstAgentPluginObject scalar integer.  Default value = %d\n",
                nstAgentPluginObject));

    netsnmp_register_int_instance("nstAgentPluginObject",
                                  nstAgentPluginObject_oid,
                                  OID_LENGTH(nstAgentPluginObject_oid),
                                  &nstAgentPluginObject, NULL);

    DEBUGMSGTL(("nstAgentPluginObject",
                "Done initalizing nstAgentPluginObject module\n"));
}
