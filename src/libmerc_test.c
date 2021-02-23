/*
 * libmerc_test.c
 *
 * main() file for libmerc.so test driver program
 *
 * Copyright (c) 2020 Cisco Systems, Inc. All rights reserved.  License at
 * https://github.com/cisco/mercury/blob/master/LICENSE
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "libmerc/libmerc.h"

unsigned char client_hello_eth[] = {
  0x00, 0x50, 0x56, 0xe0, 0xb0, 0xbc, 0x00, 0x0c, 0x29, 0x74, 0x82, 0x2f,
  0x08, 0x00, 0x45, 0x00, 0x01, 0x61, 0xd5, 0xeb, 0x40, 0x00, 0x40, 0x06,
  0x58, 0x0c, 0xc0, 0xa8, 0x71, 0xed, 0x97, 0x65, 0x41, 0xa4, 0x80, 0x2a,
  0x01, 0xbb, 0xdd, 0x07, 0xfe, 0x40, 0x25, 0x00, 0x2e, 0x63, 0x50, 0x18,
  0xfa, 0xf0, 0x0c, 0xf3, 0x00, 0x00, 0x16, 0x03, 0x01, 0x01, 0x34, 0x01,
  0x00, 0x01, 0x30, 0x03, 0x03, 0x5b, 0x1f, 0x43, 0x3b, 0x2f, 0x09, 0x1c,
  0x61, 0xff, 0xd5, 0x1d, 0x3d, 0x8f, 0x00, 0x8f, 0xea, 0x86, 0x3f, 0xb6,
  0xc3, 0x72, 0x6e, 0x7f, 0x05, 0x6b, 0x01, 0x9e, 0xc7, 0x68, 0xcd, 0x12,
  0x58, 0x20, 0xf0, 0xa3, 0x04, 0x3a, 0x4f, 0x60, 0x89, 0x7b, 0x16, 0x89,
  0xf7, 0x46, 0xcf, 0x3c, 0x69, 0x03, 0xf9, 0xf6, 0x06, 0xa7, 0x7f, 0x53,
  0x36, 0xd4, 0xe2, 0x16, 0x33, 0xe9, 0x88, 0x48, 0xff, 0x14, 0x00, 0x3e,
  0x13, 0x02, 0x13, 0x03, 0x13, 0x01, 0xc0, 0x2c, 0xc0, 0x30, 0x00, 0x9f,
  0xcc, 0xa9, 0xcc, 0xa8, 0xcc, 0xaa, 0xc0, 0x2b, 0xc0, 0x2f, 0x00, 0x9e,
  0xc0, 0x24, 0xc0, 0x28, 0x00, 0x6b, 0xc0, 0x23, 0xc0, 0x27, 0x00, 0x67,
  0xc0, 0x0a, 0xc0, 0x14, 0x00, 0x39, 0xc0, 0x09, 0xc0, 0x13, 0x00, 0x33,
  0x00, 0x9d, 0x00, 0x9c, 0x00, 0x3d, 0x00, 0x3c, 0x00, 0x35, 0x00, 0x2f,
  0x00, 0xff, 0x01, 0x00, 0x00, 0xa9, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0e,
  0x00, 0x00, 0x0b, 0x6e, 0x79, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x2e, 0x63,
  0x6f, 0x6d, 0x00, 0x0b, 0x00, 0x04, 0x03, 0x00, 0x01, 0x02, 0x00, 0x0a,
  0x00, 0x0c, 0x00, 0x0a, 0x00, 0x1d, 0x00, 0x17, 0x00, 0x1e, 0x00, 0x19,
  0x00, 0x18, 0x00, 0x23, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x17,
  0x00, 0x00, 0x00, 0x0d, 0x00, 0x30, 0x00, 0x2e, 0x04, 0x03, 0x05, 0x03,
  0x06, 0x03, 0x08, 0x07, 0x08, 0x08, 0x08, 0x09, 0x08, 0x0a, 0x08, 0x0b,
  0x08, 0x04, 0x08, 0x05, 0x08, 0x06, 0x04, 0x01, 0x05, 0x01, 0x06, 0x01,
  0x03, 0x03, 0x02, 0x03, 0x03, 0x01, 0x02, 0x01, 0x03, 0x02, 0x02, 0x02,
  0x04, 0x02, 0x05, 0x02, 0x06, 0x02, 0x00, 0x2b, 0x00, 0x09, 0x08, 0x03,
  0x04, 0x03, 0x03, 0x03, 0x02, 0x03, 0x01, 0x00, 0x2d, 0x00, 0x02, 0x01,
  0x01, 0x00, 0x33, 0x00, 0x26, 0x00, 0x24, 0x00, 0x1d, 0x00, 0x20, 0x7f,
  0x36, 0x7d, 0x60, 0x25, 0x06, 0x55, 0xca, 0xbb, 0x18, 0xd3, 0x4c, 0x84,
  0xcc, 0x5b, 0x14, 0xcd, 0x0a, 0x95, 0xe9, 0x06, 0x13, 0x5d, 0xd7, 0x6a,
  0xee, 0x62, 0x2b, 0x2b, 0x54, 0x1c, 0x17
};

uint8_t *client_hello_ip = client_hello_eth + 14;
size_t client_hello_ip_len = sizeof(client_hello_eth) - 14;

unsigned char tcp_syn[] = {
  0x00, 0x50, 0x56, 0x8e, 0x1d, 0xdc, 0x00, 0x50, 0x56, 0xa2, 0x71, 0xbf,
  0x08, 0x00, 0x45, 0x00, 0x00, 0x34, 0x58, 0x5b, 0x40, 0x00, 0x80, 0x06,
  0x41, 0x99, 0x0a, 0x0a, 0x01, 0x70, 0x0d, 0xf9, 0x47, 0x5d, 0xd2, 0x7e,
  0x01, 0xbb, 0x68, 0x4d, 0xc1, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x80, 0x02,
  0xfa, 0xf0, 0x15, 0x9b, 0x00, 0x00, 0x02, 0x04, 0x05, 0xb4, 0x01, 0x03,
  0x03, 0x08, 0x01, 0x01, 0x04, 0x02
};

unsigned char firefox_client_hello_eth[] = {
  0x00, 0x50, 0x56, 0x8e, 0x1d, 0xdc, 0x00, 0x50, 0x56, 0xa2, 0x71, 0xbf,
  0x08, 0x00, 0x45, 0x00, 0x02, 0x2d, 0x58, 0x5d, 0x40, 0x00, 0x80, 0x06,
  0x3f, 0x9e, 0x0a, 0x0a, 0x01, 0x70, 0x0d, 0xf9, 0x47, 0x5d, 0xd2, 0x7e,
  0x01, 0xbb, 0x68, 0x4d, 0xc1, 0x2e, 0xb1, 0x1b, 0xb4, 0x8d, 0x50, 0x18,
  0x04, 0x00, 0xd6, 0x50, 0x00, 0x00, 0x16, 0x03, 0x01, 0x02, 0x00, 0x01,
  0x00, 0x01, 0xfc, 0x03, 0x03, 0x3e, 0xe1, 0x7f, 0xbd, 0x7c, 0xbc, 0x30,
  0xdb, 0xa4, 0xf4, 0x74, 0xbe, 0x4a, 0x08, 0xa4, 0x8b, 0xf1, 0x5a, 0x82,
  0x78, 0x8a, 0x91, 0xf7, 0x00, 0xec, 0x25, 0xed, 0x6e, 0x5f, 0xea, 0xfb,
  0x3c, 0x20, 0x98, 0x79, 0xf8, 0xb5, 0x31, 0xed, 0x1d, 0xf8, 0x9c, 0x90,
  0x04, 0xc2, 0x0c, 0x14, 0xb8, 0x43, 0x34, 0x8e, 0x10, 0x88, 0x12, 0xa3,
  0x9a, 0x9a, 0x86, 0xab, 0x98, 0x06, 0x65, 0x4f, 0x4a, 0x86, 0x00, 0x24,
  0x13, 0x01, 0x13, 0x03, 0x13, 0x02, 0xc0, 0x2b, 0xc0, 0x2f, 0xcc, 0xa9,
  0xcc, 0xa8, 0xc0, 0x2c, 0xc0, 0x30, 0xc0, 0x0a, 0xc0, 0x09, 0xc0, 0x13,
  0xc0, 0x14, 0x00, 0x9c, 0x00, 0x9d, 0x00, 0x2f, 0x00, 0x35, 0x00, 0x0a,
  0x01, 0x00, 0x01, 0x8f, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x28, 0x00, 0x00,
  0x25, 0x66, 0x69, 0x72, 0x65, 0x66, 0x6f, 0x78, 0x2e, 0x73, 0x65, 0x74,
  0x74, 0x69, 0x6e, 0x67, 0x73, 0x2e, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63,
  0x65, 0x73, 0x2e, 0x6d, 0x6f, 0x7a, 0x69, 0x6c, 0x6c, 0x61, 0x2e, 0x63,
  0x6f, 0x6d, 0x00, 0x17, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0x00, 0x00,
  0x0a, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x1d, 0x00, 0x17, 0x00, 0x18, 0x00,
  0x19, 0x01, 0x00, 0x01, 0x01, 0x00, 0x0b, 0x00, 0x02, 0x01, 0x00, 0x00,
  0x23, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0b, 0x00, 0x09, 0x08, 0x68, 0x74,
  0x74, 0x70, 0x2f, 0x31, 0x2e, 0x31, 0x00, 0x05, 0x00, 0x05, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x6b, 0x00, 0x69, 0x00, 0x1d, 0x00,
  0x20, 0xc0, 0xab, 0xaa, 0x1f, 0xd2, 0x71, 0xdc, 0x6f, 0xc8, 0x7b, 0x4b,
  0x32, 0x65, 0xff, 0x51, 0x6c, 0x41, 0x07, 0xff, 0x9a, 0x9c, 0x54, 0x30,
  0x90, 0xbc, 0x42, 0xcf, 0x5d, 0xda, 0x3d, 0xd6, 0x57, 0x00, 0x17, 0x00,
  0x41, 0x04, 0x04, 0xbc, 0x09, 0x6a, 0x69, 0xf7, 0xc5, 0xda, 0xe6, 0x01,
  0x17, 0x9c, 0x43, 0x3d, 0x59, 0xa2, 0x78, 0xfc, 0x68, 0xeb, 0x31, 0x63,
  0x7a, 0x1c, 0xba, 0xdf, 0xe6, 0x3b, 0x9a, 0x88, 0x08, 0x36, 0x06, 0xcb,
  0xf5, 0xff, 0x08, 0x76, 0xcd, 0xb1, 0xb2, 0xdc, 0x19, 0x88, 0x1a, 0x9a,
  0x77, 0xaa, 0x4f, 0x93, 0x80, 0xdf, 0xf3, 0x7d, 0x03, 0x35, 0x63, 0x24,
  0x7c, 0x88, 0x72, 0x5c, 0xef, 0x30, 0x00, 0x2b, 0x00, 0x05, 0x04, 0x03,
  0x04, 0x03, 0x03, 0x00, 0x0d, 0x00, 0x18, 0x00, 0x16, 0x04, 0x03, 0x05,
  0x03, 0x06, 0x03, 0x08, 0x04, 0x08, 0x05, 0x08, 0x06, 0x04, 0x01, 0x05,
  0x01, 0x06, 0x01, 0x02, 0x03, 0x02, 0x01, 0x00, 0x2d, 0x00, 0x02, 0x01,
  0x01, 0x00, 0x1c, 0x00, 0x02, 0x40, 0x01, 0x00, 0x15, 0x00, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

unsigned char client_hello_no_server_name_eth[] = {
  0x00, 0x26, 0x98, 0x0b, 0x01, 0x42, 0x3c, 0x08, 0xf6, 0xd8, 0xf0, 0xc7,
  0x08, 0x00, 0x45, 0x00, 0x01, 0x11, 0x4a, 0x96, 0x40, 0x00, 0x7c, 0x06,
  0x3a, 0xa4, 0x0a, 0x52, 0xd6, 0x87, 0x2c, 0xe0, 0x6a, 0xf3, 0xd6, 0x93,
  0x01, 0xbb, 0x60, 0xac, 0xd1, 0x8b, 0x5f, 0x9e, 0xb5, 0x50, 0x50, 0x18,
  0x01, 0x04, 0x1c, 0x92, 0x00, 0x00, 0x16, 0x03, 0x01, 0x00, 0xe4, 0x01,
  0x00, 0x00, 0xe0, 0x03, 0x03, 0x2a, 0x09, 0x12, 0xec, 0x90, 0x63, 0xdf,
  0x49, 0x4b, 0xe4, 0x01, 0xbf, 0x5e, 0xbb, 0x87, 0xa1, 0x12, 0x3f, 0xa0,
  0x44, 0x63, 0x74, 0x28, 0xc1, 0x85, 0xc8, 0xc3, 0x1a, 0xab, 0xa4, 0x41,
  0x4a, 0x20, 0xe8, 0x13, 0x57, 0xf1, 0xf9, 0xfd, 0x5d, 0x83, 0x5d, 0xb8,
  0x10, 0xe1, 0x2a, 0x01, 0xca, 0x92, 0x72, 0xb7, 0x8d, 0x0b, 0xe6, 0x87,
  0x90, 0x76, 0x82, 0x77, 0x56, 0xf0, 0x9a, 0x27, 0xb7, 0xe3, 0x00, 0x42,
  0xc0, 0x30, 0xc0, 0x2c, 0xc0, 0x28, 0xc0, 0x24, 0x00, 0xa5, 0x00, 0xa1,
  0x00, 0x9f, 0x00, 0x6b, 0x00, 0x69, 0x00, 0x68, 0xc0, 0x32, 0xc0, 0x2e,
  0xc0, 0x2a, 0xc0, 0x26, 0x00, 0x9d, 0x00, 0x3d, 0xc0, 0x2f, 0xc0, 0x2b,
  0xc0, 0x27, 0xc0, 0x23, 0x00, 0xa4, 0x00, 0xa0, 0x00, 0x9e, 0x00, 0x67,
  0x00, 0x3f, 0x00, 0x3e, 0xc0, 0x31, 0xc0, 0x2d, 0xc0, 0x29, 0xc0, 0x25,
  0x00, 0x9c, 0x00, 0x3c, 0x00, 0xff, 0x01, 0x00, 0x00, 0x55, 0x00, 0x0b,
  0x00, 0x04, 0x03, 0x00, 0x01, 0x02, 0x00, 0x0a, 0x00, 0x1c, 0x00, 0x1a,
  0x00, 0x17, 0x00, 0x19, 0x00, 0x1c, 0x00, 0x1b, 0x00, 0x18, 0x00, 0x1a,
  0x00, 0x16, 0x00, 0x0e, 0x00, 0x0d, 0x00, 0x0b, 0x00, 0x0c, 0x00, 0x09,
  0x00, 0x0a, 0x00, 0x23, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x20, 0x00, 0x1e,
  0x06, 0x01, 0x06, 0x02, 0x06, 0x03, 0x05, 0x01, 0x05, 0x02, 0x05, 0x03,
  0x04, 0x01, 0x04, 0x02, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x03, 0x03,
  0x02, 0x01, 0x02, 0x02, 0x02, 0x03, 0x00, 0x0f, 0x00, 0x01, 0x01
};


// print_out_analysis_context(c) prints out information about the
// fingerprint, server_name (if present), and the result of its
// analysis; it provides an example of how to use the libmerc.h
// interface.
//
void print_out_analysis_context(const struct analysis_context *c) {

    if (c == NULL) {
        fprintf(stdout, "no analysis context (no fingerprint found)\n");
    }

    if (analysis_context_get_fingerprint_type(c) == fingerprint_type_tls) {

        fprintf(stdout, "got tls fingerprint\n");

        const char *fingerprint_string = analysis_context_get_fingerprint_string(c);
        if (fingerprint_string != NULL) {
            fprintf(stdout, "fingerprint: %s\n", fingerprint_string);
        } else {
            fprintf(stdout, "error: fingerprint string unavailable\n");
        }

        const char *server_name = analysis_context_get_server_name(c);
        if (server_name != NULL) {
            fprintf(stdout, "server_name: \"%s\"\n", server_name);
        } else {
            fprintf(stdout, "note: server_name not present\n"); // this is not an error
        }

        enum fingerprint_status status = analysis_context_get_fingerprint_status(c);
        if (status == fingerprint_status_labeled) {

            fprintf(stdout, "fingerprint status: labeled\n");

            const char *probable_process = NULL;
            double probability_score = 0.0;
            if (analysis_context_get_process_info(c,
                                                  &probable_process,
                                                  &probability_score)) {
                fprintf(stdout, "process name: \"%s\"\n", probable_process);
                fprintf(stdout, "probability score: %f\n", probability_score);
            }

            bool probable_process_is_malware = 0;
            double probability_malware = 0.0;
            if (analysis_context_get_malware_info(c,
                                                  &probable_process_is_malware,
                                                  &probability_malware)) {
                fprintf(stdout, "probable process is malware: \"%s\"\n", probable_process_is_malware ? "true" : "false");
                fprintf(stdout, "probability that process is malware: %f\n", probability_score);
            } else {
                fprintf(stdout, "malware information unavailable\n");
            }

            const struct os_information *os_info = NULL;
            size_t os_info_len = 0;
            if (analysis_context_get_os_info(c,
                                             &os_info,
                                             &os_info_len)) {
                const struct os_information *os = os_info;
                for (unsigned int i=0; i < os_info_len; i++) {
                    fprintf(stdout, "OS and prevalence: %s\t%lu\n", os->os_name, os->os_prevalence);
                    os++;
                }
            } else {
                fprintf(stdout, "OS information unavailable\n");
            }
        } else if (status == fingerprint_status_randomized) {

            fprintf(stdout, "fingerprint status: randomized\n");

        } else if (status == fingerprint_status_unlabled) {

            fprintf(stdout, "fingerprint status: unlabled\n");

        } else {

            fprintf(stdout, "fingerprint status: no information available\n");

        }

    }
}

int main(int argc, char *argv[]) {

    // initialize libmerc's global configuration by creating a
    // libmerc_config structure and then passing it into mercury_init
    //
    struct libmerc_config config = libmerc_config_init();
    config.do_analysis = true;
    config.resources = "../resources";
    config.report_os = true;
    config.packet_filter_cfg = "tls";
    int verbosity = 0;
    int retval = mercury_init(&config, verbosity);
    if (retval) {
        fprintf(stderr, "mercury_init() error (code %d)\n", retval);
        return EXIT_FAILURE;
    }

    // initialize a mercury_packer_processor, which is an opaque
    // pointer; there should be one mercury_packet_processor for each
    // packet-processing thread
    //
    mercury_packet_processor m = mercury_packet_processor_construct();
    if (m == NULL) {
        fprintf(stderr, "error in mercury_packet_processor_construct()\n");
        return EXIT_FAILURE;
    }

    // pass a packet and timestamp into the packet processor, and get
    // back a pointer to an analysis_context (or a NULL)
    //
    struct timespec time;
    time.tv_sec = time.tv_nsec = 0;  // set to January 1st, 1970 (the Epoch)
    const struct analysis_context *c = mercury_packet_processor_ip_get_analysis_context(m,
                                                                                        client_hello_ip,
                                                                                        client_hello_ip_len,
                                                                                        &time);
    // print out fingerprint, server_name, and analysis results
    //
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
    fprintf(stdout, "analysis context for client_hello IP packet\n");
    print_out_analysis_context(c);

    // pass tcp syn packet to processor; should get negative response
    //
    c = mercury_packet_processor_get_analysis_context(m,
                                                      tcp_syn,
                                                      sizeof(tcp_syn),
                                                      &time);
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
    fprintf(stdout, "analysis context for TCP SYN packet\n");
    print_out_analysis_context(c);

    // pass ethernet packet to processor, then print out context
    //
    c = mercury_packet_processor_get_analysis_context(m,
                                                      client_hello_eth,
                                                      sizeof(client_hello_eth),
                                                      &time);
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
    fprintf(stdout, "analysis context for client_hello ethernet packet\n");
    print_out_analysis_context(c);

    // pass no-server-name ethernet packet to processor, then print out context
    //
    c = mercury_packet_processor_get_analysis_context(m,
                                                      client_hello_no_server_name_eth,
                                                      sizeof(client_hello_no_server_name_eth),
                                                      &time);
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
    fprintf(stdout, "analysis context for no-server-name client_hello ethernet packet\n");
    print_out_analysis_context(c);

    // tear down packet processor
    //
    mercury_packet_processor_destruct(m);

    // tear down library's global configuration
    //
    retval = mercury_finalize();
    if (retval) {
        fprintf(stderr, "mercury_finalize() error (code %d)\n", retval);
        return EXIT_FAILURE;
    }

    return 0;
}
