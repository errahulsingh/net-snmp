/*
 * This file was generated by mib2c and is intended for use as
 * a mib module for the ucd-snmp snmpd agent. 
 */


/*
 * This should always be included first before anything else 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

#ifndef NETSNMP_NO_WRITE_SUPPORT
netsnmp_feature_require(header_complex_find_entry)
#endif /* NETSNMP_NO_WRITE_SUPPORT */

/*
 * minimal include directives 
 */
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "header_complex.h"
#include "mteTriggerTable.h"
#include "mteObjectsTable.h"


/*
 * mteObjectsTable_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */


oid             mteObjectsTable_variables_oid[] =
    { 1, 3, 6, 1, 2, 1, 88, 1, 3, 1 };


/*
 * variable2 mteObjectsTable_variables:
 *   this variable defines function callbacks and type return information 
 *   for the mteObjectsTable mib section 
 */


#ifndef NETSNMP_NO_WRITE_SUPPORT
struct variable2 mteObjectsTable_variables[] = {
    /*
     * magic number        , variable type , ro/rw , callback fn  , L, oidsuffix 
     */
#define   MTEOBJECTSID          5
    {MTEOBJECTSID, ASN_OBJECT_ID, NETSNMP_OLDAPI_RWRITE,
     var_mteObjectsTable, 2, {1, 3}},
#define   MTEOBJECTSIDWILDCARD  6
    {MTEOBJECTSIDWILDCARD, ASN_INTEGER, NETSNMP_OLDAPI_RWRITE,
     var_mteObjectsTable, 2, {1, 4}},
#define   MTEOBJECTSENTRYSTATUS  7
    {MTEOBJECTSENTRYSTATUS, ASN_INTEGER, NETSNMP_OLDAPI_RWRITE,
     var_mteObjectsTable, 2, {1, 5}},

};
#else /* !NETSNMP_NO_WRITE_SUPPORT */
struct variable2 mteObjectsTable_variables[] = {
    /*
     * magic number        , variable type , ro/rw , callback fn  , L, oidsuffix 
     */
#define   MTEOBJECTSID          5
    {MTEOBJECTSID, ASN_OBJECT_ID, NETSNMP_OLDAPI_RONLY,
     var_mteObjectsTable, 2, {1, 3}},
#define   MTEOBJECTSIDWILDCARD  6
    {MTEOBJECTSIDWILDCARD, ASN_INTEGER, NETSNMP_OLDAPI_RONLY,
     var_mteObjectsTable, 2, {1, 4}},
#define   MTEOBJECTSENTRYSTATUS  7
    {MTEOBJECTSENTRYSTATUS, ASN_INTEGER, NETSNMP_OLDAPI_RONLY,
     var_mteObjectsTable, 2, {1, 5}},

};
#endif /* !NETSNMP_NO_WRITE_SUPPORT */

/*
 * (L = length of the oidsuffix) 
 */


/*
 * global storage of our data, saved in and configured by header_complex() 
 */
static struct header_complex_index *mteObjectsTableStorage = NULL;




/*
 * init_mteObjectsTable():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void
init_mteObjectsTable(void)
{
    DEBUGMSGTL(("mteObjectsTable", "initializing...  "));


    /*
     * register ourselves with the agent to handle our mib tree 
     */
    REGISTER_MIB("mteObjectsTable", mteObjectsTable_variables, variable2,
                 mteObjectsTable_variables_oid);


    /*
     * register our config handler(s) to deal with registrations 
     */
    snmpd_register_config_handler("mteObjectsTable", parse_mteObjectsTable,
                                  NULL, NULL);


    /*
     * we need to be called back later to store our data 
     */
    snmp_register_callback(SNMP_CALLBACK_LIBRARY, SNMP_CALLBACK_STORE_DATA,
                           store_mteObjectsTable, NULL);


    /*
     * place any other initialization junk you need here 
     */


    DEBUGMSGTL(("mteObjectsTable", "done.\n"));
}


/*
 * mteObjectsTable_add(): adds a structure node to our data set 
 */
int
mteObjectsTable_add(struct mteObjectsTable_data *thedata)
{
    netsnmp_variable_list *vars = NULL;


    DEBUGMSGTL(("mteObjectsTable", "adding data...  "));
    /*
     * add the index variables to the varbind list, which is 
     * used by header_complex to index the data 
     */


    snmp_varlist_add_variable(&vars, NULL, 0, ASN_OCTET_STR, (char *) thedata->mteOwner, thedata->mteOwnerLen); /* mteOwner */
    snmp_varlist_add_variable(&vars, NULL, 0, ASN_OCTET_STR, (char *) thedata->mteObjectsName, thedata->mteObjectsNameLen);     /* mteObjectsName */
    snmp_varlist_add_variable(&vars, NULL, 0, ASN_UNSIGNED, (char *) &thedata->mteObjectsIndex, sizeof(thedata->mteObjectsIndex));      /* mteObjectsIndex */



    header_complex_add_data(&mteObjectsTableStorage, vars, thedata);
    DEBUGMSGTL(("mteObjectsTable", "registered an entry\n"));


    DEBUGMSGTL(("mteObjectsTable", "done.\n"));
    return SNMPERR_SUCCESS;
}


/*
 * parse_mteObjectsTable():
 *   parses .conf file entries needed to configure the mib.
 */
void
parse_mteObjectsTable(const char *token, char *line)
{
    size_t          tmpint;
    struct mteObjectsTable_data *StorageTmp =
        SNMP_MALLOC_STRUCT(mteObjectsTable_data);

    DEBUGMSGTL(("mteObjectsTable", "parsing config...  "));


    if (StorageTmp == NULL) {
        config_perror("malloc failure");
        return;
    }


    line =
        read_config_read_data(ASN_OCTET_STR, line, &StorageTmp->mteOwner,
                              &StorageTmp->mteOwnerLen);
    if (StorageTmp->mteOwner == NULL) {
        config_perror("invalid specification for mteOwner");
        return;
    }

    line =
        read_config_read_data(ASN_OCTET_STR, line,
                              &StorageTmp->mteObjectsName,
                              &StorageTmp->mteObjectsNameLen);
    if (StorageTmp->mteObjectsName == NULL) {
        config_perror("invalid specification for mteObjectsName");
        return;
    }

    line =
        read_config_read_data(ASN_UNSIGNED, line,
                              &StorageTmp->mteObjectsIndex, &tmpint);

    line =
        read_config_read_data(ASN_OBJECT_ID, line,
                              &StorageTmp->mteObjectsID,
                              &StorageTmp->mteObjectsIDLen);
    if (StorageTmp->mteObjectsID == NULL) {
        config_perror("invalid specification for mteObjectsID");
        return;
    }

    line =
        read_config_read_data(ASN_INTEGER, line,
                              &StorageTmp->mteObjectsIDWildcard, &tmpint);

    line =
        read_config_read_data(ASN_INTEGER, line,
                              &StorageTmp->mteObjectsEntryStatus, &tmpint);




    mteObjectsTable_add(StorageTmp);


    DEBUGMSGTL(("mteObjectsTable", "done.\n"));
}




/*
 * store_mteObjectsTable():
 *   stores .conf file entries needed to configure the mib.
 */
int
store_mteObjectsTable(int majorID, int minorID, void *serverarg,
                      void *clientarg)
{
    char            line[SNMP_MAXBUF];
    char           *cptr;
    size_t          tmpint;
    struct mteObjectsTable_data *StorageTmp;
    struct header_complex_index *hcindex;


    DEBUGMSGTL(("mteObjectsTable", "storing data...  "));


    for (hcindex = mteObjectsTableStorage; hcindex != NULL;
         hcindex = hcindex->next) {
        StorageTmp = (struct mteObjectsTable_data *) hcindex->data;

        if (StorageTmp->storagetype != ST_READONLY) {
            memset(line, 0, sizeof(line));
            strcat(line, "mteObjectsTable ");
            cptr = line + strlen(line);


            cptr =
                read_config_store_data(ASN_OCTET_STR, cptr,
                                       &StorageTmp->mteOwner,
                                       &StorageTmp->mteOwnerLen);
            cptr =
                read_config_store_data(ASN_OCTET_STR, cptr,
                                       &StorageTmp->mteObjectsName,
                                       &StorageTmp->mteObjectsNameLen);
            cptr =
                read_config_store_data(ASN_UNSIGNED, cptr,
                                       &StorageTmp->mteObjectsIndex,
                                       &tmpint);
            cptr =
                read_config_store_data(ASN_OBJECT_ID, cptr,
                                       &StorageTmp->mteObjectsID,
                                       &StorageTmp->mteObjectsIDLen);
            cptr =
                read_config_store_data(ASN_INTEGER, cptr,
                                       &StorageTmp->mteObjectsIDWildcard,
                                       &tmpint);
            cptr =
                read_config_store_data(ASN_INTEGER, cptr,
                                       &StorageTmp->mteObjectsEntryStatus,
                                       &tmpint);



            snmpd_store_config(line);
        }
    }
    DEBUGMSGTL(("mteObjectsTable", "done.\n"));
    return SNMPERR_SUCCESS;
}




/*
 * var_mteObjectsTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_mteObjectsTable above.
 */
unsigned char  *
var_mteObjectsTable(struct variable *vp,
                    oid * name,
                    size_t * length,
                    int exact,
                    size_t * var_len, WriteMethod ** write_method)
{


    struct mteObjectsTable_data *StorageTmp = NULL;


    DEBUGMSGTL(("mteObjectsTable",
                "var_mteObjectsTable: Entering...  \n"));

	/* set default value */
	*write_method = NULL;

    /*
     * this assumes you have registered all your data properly
     */
    if ((StorageTmp =
         header_complex(mteObjectsTableStorage, vp, name, length, exact,
                        var_len, write_method)) == NULL) {
        if (vp->magic == MTEOBJECTSENTRYSTATUS)
            *write_method = write_mteObjectsEntryStatus;
        return NULL;
    }

    /*
     * this is where we do the value assignments for the mib results.
     */
    switch (vp->magic) {


    case MTEOBJECTSID:
#ifndef NETSNMP_NO_WRITE_SUPPORT
        *write_method = write_mteObjectsID;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */
        *var_len = (StorageTmp->mteObjectsIDLen) * sizeof(oid);
        return (u_char *) StorageTmp->mteObjectsID;

    case MTEOBJECTSIDWILDCARD:
#ifndef NETSNMP_NO_WRITE_SUPPORT
        *write_method = write_mteObjectsIDWildcard;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */
        *var_len = sizeof(StorageTmp->mteObjectsIDWildcard);
        return (u_char *) & StorageTmp->mteObjectsIDWildcard;

    case MTEOBJECTSENTRYSTATUS:
#ifndef NETSNMP_NO_WRITE_SUPPORT
        *write_method = write_mteObjectsEntryStatus;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */
        *var_len = sizeof(StorageTmp->mteObjectsEntryStatus);
        return (u_char *) & StorageTmp->mteObjectsEntryStatus;


    default:
        ERROR_MSG("");
    }
    return NULL;
}



#ifndef NETSNMP_NO_WRITE_SUPPORT

int
write_mteObjectsID(int action,
                   u_char * var_val,
                   u_char var_val_type,
                   size_t var_val_len,
                   u_char * statP, oid * name, size_t name_len)
{
    static oid     *tmpvar;
    struct mteObjectsTable_data *StorageTmp = NULL;
    static size_t   tmplen;
    size_t          newlen =
        name_len - (sizeof(mteObjectsTable_variables_oid) / sizeof(oid) +
                    3 - 1);


    DEBUGMSGTL(("mteObjectsTable",
                "write_mteObjectsID entering action=%d...  \n", action));
    if ((StorageTmp =
         header_complex(mteObjectsTableStorage, NULL,
                        &name[sizeof(mteObjectsTable_variables_oid) /
                              sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */

    if (StorageTmp && StorageTmp->storagetype == ST_READONLY) {
        return SNMP_ERR_NOTWRITABLE;
    }

    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_OBJECT_ID) {
            snmp_log(LOG_ERR, "write to mteObjectsID not ASN_OBJECT_ID\n");
            return SNMP_ERR_WRONGTYPE;
        }
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in objid for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteObjectsID;
        tmplen = StorageTmp->mteObjectsIDLen;
        StorageTmp->mteObjectsID = netsnmp_memdup(var_val, var_val_len);
        StorageTmp->mteObjectsIDLen = var_val_len / sizeof(oid);
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        SNMP_FREE(StorageTmp->mteObjectsID);
        StorageTmp->mteObjectsID = tmpvar;
        StorageTmp->mteObjectsIDLen = tmplen;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        SNMP_FREE(tmpvar);

        snmp_store_needed(NULL);

        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_mteObjectsIDWildcard(int action,
                           u_char * var_val,
                           u_char var_val_type,
                           size_t var_val_len,
                           u_char * statP, oid * name, size_t name_len)
{
    static int      tmpvar;
    struct mteObjectsTable_data *StorageTmp = NULL;
    size_t          newlen =
        name_len - (sizeof(mteObjectsTable_variables_oid) / sizeof(oid) +
                    3 - 1);


    DEBUGMSGTL(("mteObjectsTable",
                "write_mteObjectsIDWildcard entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteObjectsTableStorage, NULL,
                        &name[sizeof(mteObjectsTable_variables_oid) /
                              sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */

    if (StorageTmp && StorageTmp->storagetype == ST_READONLY) {
        return SNMP_ERR_NOTWRITABLE;
    }

    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_INTEGER) {
            snmp_log(LOG_ERR,
                     "write to mteObjectsIDWildcard not ASN_INTEGER\n");
            return SNMP_ERR_WRONGTYPE;
        }
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in long_ret for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteObjectsIDWildcard;
        StorageTmp->mteObjectsIDWildcard = *((long *) var_val);
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        StorageTmp->mteObjectsIDWildcard = tmpvar;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */

        snmp_store_needed(NULL);

        break;
    }
    return SNMP_ERR_NOERROR;
}






int
write_mteObjectsEntryStatus(int action,
                            u_char * var_val,
                            u_char var_val_type,
                            size_t var_val_len,
                            u_char * statP, oid * name, size_t name_len)
{
    struct mteObjectsTable_data *StorageTmp = NULL;
    static struct mteObjectsTable_data *StorageNew, *StorageDel;
    size_t          newlen =
        name_len - (sizeof(mteObjectsTable_variables_oid) / sizeof(oid) +
                    3 - 1);
    static int      old_value;
    int             set_value;
    static netsnmp_variable_list *vars, *vp;
    struct header_complex_index *hciptr;


    StorageTmp =
        header_complex(mteObjectsTableStorage, NULL,
                       &name[sizeof(mteObjectsTable_variables_oid) /
                             sizeof(oid) + 3 - 1], &newlen, 1, NULL, NULL);

    if (var_val_type != ASN_INTEGER || var_val == NULL) {
        snmp_log(LOG_ERR,
                 "write to mteObjectsEntryStatus not ASN_INTEGER\n");
        return SNMP_ERR_WRONGTYPE;
    }

    if (StorageTmp && StorageTmp->storagetype == ST_READONLY) {
        return SNMP_ERR_NOTWRITABLE;
    }

    set_value = *((long *) var_val);


    /*
     * check legal range, and notReady is reserved for us, not a user 
     */
    if (set_value < 1 || set_value > 6 || set_value == RS_NOTREADY)
        return SNMP_ERR_INCONSISTENTVALUE;


    switch (action) {
    case RESERVE1:
        /*
         * stage one: test validity 
         */
        if (StorageTmp == NULL) {
            /*
             * create the row now? 
             */


            /*
             * ditch illegal values now 
             */
            if (set_value == RS_ACTIVE || set_value == RS_NOTINSERVICE)
                return SNMP_ERR_INCONSISTENTVALUE;


            /*
             * destroying a non-existent row is actually legal 
             */
            if (set_value == RS_DESTROY) {
                return SNMP_ERR_NOERROR;
            }


            /*
             * illegal creation values 
             */
            if (set_value == RS_ACTIVE || set_value == RS_NOTINSERVICE) {
                return SNMP_ERR_INCONSISTENTVALUE;
            }
        } else {
            /*
             * row exists.  Check for a valid state change 
             */
            if (set_value == RS_CREATEANDGO
                || set_value == RS_CREATEANDWAIT) {
                /*
                 * can't create a row that exists 
                 */
                return SNMP_ERR_INCONSISTENTVALUE;
            }
            /*
             * XXX: interaction with row storage type needed 
             */
        }
        break;




    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        if (StorageTmp == NULL) {
            /*
             * creation 
             */
            vars = NULL;


            snmp_varlist_add_variable(&vars, NULL, 0, ASN_OCTET_STR, NULL, 0);  /* mteOwner */
            snmp_varlist_add_variable(&vars, NULL, 0, ASN_OCTET_STR, NULL, 0);  /* mteObjectsName */
            snmp_varlist_add_variable(&vars, NULL, 0, ASN_UNSIGNED, NULL, 0);   /* mteObjectsIndex */

            if (header_complex_parse_oid
                (&
                 (name
                  [sizeof(mteObjectsTable_variables_oid) / sizeof(oid) +
                   2]), newlen, vars) != SNMPERR_SUCCESS) {
                /*
                 * XXX: free, zero vars 
                 */
                return SNMP_ERR_INCONSISTENTNAME;
            }
            vp = vars;


            StorageNew = SNMP_MALLOC_STRUCT(mteObjectsTable_data);
            if (StorageNew == NULL)
                return SNMP_ERR_GENERR;
            StorageNew->mteOwner = netsnmp_strdup_and_null(vp->val.string,
                                                           vp->val_len);
            StorageNew->mteOwnerLen = vp->val_len;
            vp = vp->next_variable;
            StorageNew->mteObjectsName  =
                netsnmp_strdup_and_null(vp->val.string,
                                        vp->val_len);
            StorageNew->mteObjectsNameLen = vp->val_len;
            vp = vp->next_variable;
            StorageNew->mteObjectsIndex = *(vp->val.integer);

            /*
             * XXX: fill in default row values here into StorageNew 
             */
            StorageNew->mteObjectsID = calloc(1, sizeof(oid) * sizeof(2));      /* 0.0 */
            StorageNew->mteObjectsIDLen = 2;
            StorageNew->mteObjectsIDWildcard = MTEOBJECTSIDWILDCARD_FALSE;

            StorageNew->mteObjectsEntryStatus = set_value;
            /*
             * XXX: free, zero vars, no longer needed? 
             */
        }


        break;




    case FREE:
        /*
         * XXX: free, zero vars 
         */
        /*
         * Release any resources that have been allocated 
         */
        break;




    case ACTION:
        /*
         * The variable has been stored in set_value for you to
         * use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in
         * the UNDO case 
         */


        if (StorageTmp == NULL) {
            /*
             * row creation, so add it 
             */
            if (StorageNew != NULL)
                mteObjectsTable_add(StorageNew);
            /*
             * XXX: ack, and if it is NULL? 
             */
        } else if (set_value != RS_DESTROY) {
            /*
             * set the flag? 
             */
            old_value = StorageTmp->mteObjectsEntryStatus;
            StorageTmp->mteObjectsEntryStatus = *((long *) var_val);
        } else {
            /*
             * destroy...  extract it for now 
             */
            hciptr =
                header_complex_find_entry(mteObjectsTableStorage,
                                          StorageTmp);
            StorageDel =
                header_complex_extract_entry(&mteObjectsTableStorage,
                                             hciptr);
        }
        break;




    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        if (StorageTmp == NULL) {
            /*
             * row creation, so remove it again 
             */
            hciptr =
                header_complex_find_entry(mteObjectsTableStorage,
                                          StorageTmp);
            StorageDel =
                header_complex_extract_entry(&mteObjectsTableStorage,
                                             hciptr);
            /*
             * XXX: free it 
             */
        } else if (StorageDel != NULL) {
            /*
             * row deletion, so add it again 
             */
            mteObjectsTable_add(StorageDel);
        } else {
            StorageTmp->mteObjectsEntryStatus = old_value;
        }
        break;




    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        if (StorageDel != NULL) {
            StorageDel = NULL;
            /*
             * XXX: free it, its dead 
             */
        } else {
            if (StorageTmp
                && StorageTmp->mteObjectsEntryStatus == RS_CREATEANDGO) {
                StorageTmp->mteObjectsEntryStatus = RS_ACTIVE;
            } else if (StorageTmp &&
                       StorageTmp->mteObjectsEntryStatus ==
                       RS_CREATEANDWAIT) {
                StorageTmp->mteObjectsEntryStatus = RS_NOTINSERVICE;
            }
        }
        snmp_store_needed(NULL);

        break;
    }
    return SNMP_ERR_NOERROR;
}

#endif /* !NETSNMP_NO_WRITE_SUPPORT */


void
mte_add_objects(netsnmp_variable_list * vars,
                struct mteTriggerTable_data *item, const char *owner,
                const char *name, oid * suffix, size_t suffix_len)
{
    struct header_complex_index *hcptr = mteObjectsTableStorage;

    DEBUGMSGTL(("mteObjectsTable",
                "Searching for objects to add for owner=%s / name=%s\n",
                owner, name));

    if (vars == NULL || item == NULL || owner == NULL || name == NULL ||
        hcptr == NULL)
        return;

    /*
     * get to end of variable chain 
     */
    while (vars->next_variable != NULL)
        vars = vars->next_variable;


    /*
     * get to start of objects list 
     */
    while (hcptr &&
           (strcmp(((struct mteObjectsTable_data *) hcptr->data)->mteOwner,
                   owner) != 0 ||
            strcmp(((struct mteObjectsTable_data *) hcptr->data)->
                   mteObjectsName, name) != 0))
        hcptr = hcptr->next;

    /*
     * add all objects 
     */
    while (hcptr &&
           strcmp(((struct mteObjectsTable_data *) hcptr->data)->mteOwner,
                  owner) == 0 &&
           strcmp(((struct mteObjectsTable_data *) hcptr->data)->
                  mteObjectsName, name) == 0) {
        /*
         * loop through objects 
         */
        netsnmp_pdu    *pdu = NULL, *response = NULL;
        struct mteObjectsTable_data *node =
            (struct mteObjectsTable_data *) hcptr->data;
        oid             theoid[MAX_OID_LEN];
        size_t          theoid_len;

        /*
         * copy in the suffix 
         */
        memcpy(theoid, node->mteObjectsID,
               node->mteObjectsIDLen * sizeof(oid));
        theoid_len = node->mteObjectsIDLen;
        if (node->mteObjectsIDWildcard == MTEOBJECTSIDWILDCARD_TRUE &&
            suffix && suffix_len > 0) {
            theoid_len += suffix_len;
            if (theoid_len > MAX_OID_LEN) {
                break;          /* XXX: properly send trap or something? */
            }

            memcpy(&theoid[node->mteObjectsIDLen], suffix,
                   suffix_len * sizeof(oid));
        }

        /*
         * retrieve the value 
         */
        pdu = snmp_pdu_create(SNMP_MSG_GET);
        snmp_add_null_var(pdu, theoid, theoid_len);
        response = mte_get_response(item, pdu);

        if (response) {
            if (vars) {
                vars->next_variable = response->variables;
                vars = vars->next_variable;
                DEBUGMSGTL(("mteObjectsTable", "Adding:  "));
                DEBUGMSGOID(("mteObjectsTable", response->variables->name,
                             response->variables->name_length));
                DEBUGMSG(("mteObjectsTable", "\n"));
            } else {
                vars = response->variables;
            }
            /*
             * erase response notion of the values we stole from it 
             */
            response->variables = NULL;
            snmp_free_pdu(response);
        }

        /*
         * move along 
         */
        hcptr = hcptr->next;
    }
    DEBUGMSGTL(("mteObjectsTable", "Done adding objects\n"));
}

int
mte_add_object_to_table(const char *owner, const char *objname,
                        oid * oidname, size_t oidname_len, int iswild)
{
    struct header_complex_index *hcptr = mteObjectsTableStorage, *lastnode;
    static struct mteObjectsTable_data *StorageNew;

    /*
     * malloc initial struct 
     */
    StorageNew = SNMP_MALLOC_STRUCT(mteObjectsTable_data);
    if (StorageNew == NULL)
        return SNMP_ERR_GENERR;
    StorageNew->mteOwner = netsnmp_strdup_and_null(owner, strlen(owner));
    StorageNew->mteOwnerLen = strlen(owner);
    StorageNew->mteObjectsName = netsnmp_strdup_and_null(objname,
                                                         strlen(objname));
    StorageNew->mteObjectsNameLen = strlen(objname);

    /*
     * find the next number 
     */
    /*
     * get to start of objects list 
     */
    while (hcptr &&
           (strcmp(((struct mteObjectsTable_data *) hcptr->data)->mteOwner,
                   owner) != 0 ||
            strcmp(((struct mteObjectsTable_data *) hcptr->data)->
                   mteObjectsName, objname) != 0))
        hcptr = hcptr->next;

    if (hcptr) {
        /*
         * an object existed.  Find the first one past and increment
         * the previous number 
         */
        lastnode = hcptr;
        while (hcptr &&
               strcmp(((struct mteObjectsTable_data *) hcptr->data)->
                      mteOwner, owner) == 0
               && strcmp(((struct mteObjectsTable_data *) hcptr->data)->
                         mteObjectsName, objname) == 0) {
            lastnode = hcptr;
            hcptr = hcptr->next;
        }
        StorageNew->mteObjectsIndex =
            ((struct mteObjectsTable_data *) lastnode->data)->
            mteObjectsIndex + 1;
    } else {
        StorageNew->mteObjectsIndex = 1;
    }

    /*
     * XXX: fill in default row values here into StorageNew 
     */
    StorageNew->mteObjectsID = snmp_duplicate_objid(oidname, oidname_len);
    StorageNew->mteObjectsIDLen = oidname_len;

    if (iswild)
        StorageNew->mteObjectsIDWildcard = MTEOBJECTSIDWILDCARD_TRUE;
    else
        StorageNew->mteObjectsIDWildcard = MTEOBJECTSIDWILDCARD_FALSE;

    StorageNew->mteObjectsEntryStatus = RS_ACTIVE;
    StorageNew->storagetype = ST_READONLY;
    return mteObjectsTable_add(StorageNew);
}
