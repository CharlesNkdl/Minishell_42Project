#include "../inc/minishell.h"

void	printstrtab(char **str)
{
	char *buffer;
	char *nl = "\n";

	while (*str)
	{
		buffer = *str;
		while (*buffer)
		{
			write(1,buffer, 1);
			buffer++;
		}
		write(1,nl,1);
		str++;
	}
}

void print_stat(struct stat st)
{
    printf("File Permissions: ");
    printf((st.st_mode & S_IRUSR) ? "r" : "-");
    printf((st.st_mode & S_IWUSR) ? "w" : "-");
    printf((st.st_mode & S_IXUSR) ? "x" : "-");
    printf((st.st_mode & S_IRGRP) ? "r" : "-");
    printf((st.st_mode & S_IWGRP) ? "w" : "-");
    printf((st.st_mode & S_IXGRP) ? "x" : "-");
    printf((st.st_mode & S_IROTH) ? "r" : "-");
    printf((st.st_mode & S_IWOTH) ? "w" : "-");
    printf((st.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("File Size: %ld bytes\n", st.st_size);
    printf("Number of Hard Links: %ld\n", st.st_nlink);
    printf("User ID: %d\n", st.st_uid);
    printf("Group ID: %d\n", st.st_gid);
    printf("Last Access Time: %ld\n", st.st_atime);
    printf("Last Modification Time: %ld\n", st.st_mtime);
    printf("Last Status Change Time: %ld\n", st.st_ctime);
}

void print_dirent(struct dirent *entry)
{
    printf("Name: %s\n", entry->d_name);
    printf("Inode Number: %ld\n", entry->d_ino);
    printf("Directory Entry Type: ");

    if (entry->d_type == DT_REG)
        printf("Regular File\n");
    else if (entry->d_type == DT_DIR)
        printf("Directory\n");
    else if (entry->d_type == DT_FIFO)
        printf("FIFO (Named Pipe)\n");
    else if (entry->d_type == DT_BLK)
        printf("Block Device\n");
    else if (entry->d_type == DT_CHR)
        printf("Character Device\n");
    else if (entry->d_type == DT_LNK)
        printf("Symbolic Link\n");
    else if (entry->d_type == DT_SOCK)
        printf("Socket\n");
    else
	{
        printf("Unknown\n");
	}
	printf("offset to the next dir : %ld \n", entry->d_off);
	printf("length of this record : %hu \n", entry->d_reclen);
}

