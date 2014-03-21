#if !defined(INFO_H)
#define INFO_H

long brighter(char *ID_name, double value);
/* number of pixels brighter than value */

int img_nbpix_flux(char *ID_name);

double img_percentile(char *ID_name, double p);

int img_histoc(char *ID_name, char *fname);

int make_histogram(char *ID_name, char *ID_out_name, double min, double max, long nbsteps);

double ssquare(char *ID_name);

double rms_dev(char *ID_name);

int stats(char *ID_name, char *options);

double img_min(char *ID_name);

double img_max(char *ID_name);

int profile(char *ID_name, char *outfile, double xcenter, double ycenter, double step, long nb_step);

int profile2im(char *profile_name, long nbpoints, long size, double xcenter, double ycenter, double radius, char *out);

int printpix(char *ID_name, char *filename);

double background_photon_noise(char *ID_name);

int test_structure_function(char *ID_name, long NBpoints, char *fname);

int full_structure_function(char *ID_name, long NBpoints, char *ID_out);

int fft_structure_function(char *ID_in, char *ID_out);

#endif
