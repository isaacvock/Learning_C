#include <stdio.h>
#include <htslib/sam.h>

int main(int argc, char *argv[]){

    // Open bam file
    samFile *fp_in = hts_open(argv[1], "r");
    printf("Opened bam file\n");

    // Read header
    bam_hdr_t *bamHdr = sam_hdr_read(fp_in); 
    printf("Read header\n");

    // Initialize an alignment
    bam1_t *aln = bam_init1();
    printf("Initialized alignment\n");

    char *chrom = argv[2];
    int locus = atoi(argv[3]);
    int comp;

    printf("%s\t%d\n", chrom, locus);

    while(sam_read1(fp_in, bamHdr,aln) > 0){

        // Left most position of alignment
        int32_t pos = aln->core.pos +1;

        // Contig name (chromosome)
        char *chr = bamHdr->target_name[aln->core.tid];

        // Length of the read
        uint32_t len = aln->core.l_qseq;

        //Quality string
        uint8_t *q = bam_get_seq(aln);

        //Mapping quality
        uint32_t q2 = aln->core.qual;

        // CIGAR string
        uint32_t *cigar = bam_get_cigar(aln);


        char *qseq = (char *)malloc(len);

        for(int i = 0; i < len; i++){
            // Convert nucleotide ID to IUPAC ID
            qseq[i] = seq_nt16_str[bam_seqi(q,i)];
        }

        if(strcmp(chrom, chr) == 0){

			if(locus > pos+len){
				printf("%s\t%d\t%d\t%s\t%s\t%d\n",chr,pos,len,qseq,q,q2);
			}
        }

    }

    bam_destroy1(aln);
    sam_close(fp_in);
}