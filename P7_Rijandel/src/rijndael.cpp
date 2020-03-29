#include "../include/rijndael.hpp"
// para acceder a las posiciones => pos = i * tmño_fila + j

rijndael::rijndael()
{
    set_Rcon();
    set_Scon();
    est_inter.resize(4);
    for (int i = 0; i < 4; i++)
    {
        est_inter[i].resize(4);
    }
}

rijndael::~rijndael()
{
}

void rijndael::set_Rcon()
{
    Rc.resize(10);
    Rc[0] = {0x1, 0x0, 0x0, 0x0};
    Rc[1] = {0x2, 0x0, 0x0, 0x0};
    Rc[2] = {0x4, 0x0, 0x0, 0x0};
    Rc[3] = {0x8, 0x0, 0x0, 0x0};
    Rc[4] = {0x10, 0x0, 0x0, 0x0};
    Rc[5] = {0x20, 0x0, 0x0, 0x0};
    Rc[6] = {0x40, 0x0, 0x0, 0x0};
    Rc[7] = {0x80, 0x0, 0x0, 0x0};
    Rc[8] = {0x1B, 0x0, 0x0, 0x0};
    Rc[9] = {0x36, 0x0, 0x0, 0x0};
}

void rijndael::set_Scon()
{
    Sbox = {
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};
}


void rijndael::set_key(std::vector<std::vector<int>> key)
{
    key_ = key; // guardamos la clave sin expandir
    expkey_.resize(4);
    // la clave expandida guarda 11 matrices de 4 x 4
    // es decir, 4 filas por 44 columnas
    for (int i = 0; i < 4; i++)
    {
        expkey_[i].resize(44);
        for (int j = 0; j < 4; j++)
        {
            expkey_[i][j] = key[i][j];
        }
    }
}

void rijndael::set_entrada(std::vector<std::vector<int>> entrada)
{
    entrada_ = entrada;
}

/**
 * Expansión de la clave obteniendo 10 subclaves a partir de la original
 */
void rijndael::expan_key()
{
    int copy;
    int iter_rc = 0;
    std::vector<int> W_1;
    W_1.resize(4); // Wi - 1
    std::vector<int> W_4;
    W_4.resize(4); // Wi - 4

    for (int j = 4; j < 44; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            W_1[i] = expkey_[i][j - 1]; // columna anterior (byte anterior)
            W_4[i] = expkey_[i][j - 4]; // guardamos el primer byte de la matriz anterior
        }
        if (j % 4 == 0)
        {
            // RotWord // cada 4 columnas
            // el primer elemento se coloca abajo
            // y rodamos los demas hacia arriba
            copy = W_1[0];
            W_1[0] = W_1[1];
            W_1[1] = W_1[2];
            W_1[2] = W_1[3];
            W_1[3] = copy;


            // Sub Bytes
            for (int k = 0; k < 4; k++)
            {
                W_1[k] = Sbox[W_1[k]];
            }

            for (int i = 0; i < 4; i++)
            {
                expkey_[i][j] = W_4[i] ^ W_1[i] ^ Rc[iter_rc][i]; // peude ser módulo 10
            }
            iter_rc++;
        }
        else // para las columnas que no son múltiplo de 4
        {
            // std::cout << "Nueva columna: ";
            for (int i = 0; i < 4; i++)
            {
                expkey_[i][j] = W_1[i] ^ W_4[i];
            }
        }
    }
}

void rijndael::AddRoundKey1()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            est_inter[i][j] = entrada_[i][j] ^ key_[i][j];
        }
    }
    
    std::cout << std::endl << "Iteración 0: " << std::endl;

    std::cout << "Subclave = ";
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            std::cout << expkey_[i][j] << " ";
        }
    }

    std::cout << " = ";

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            std::cout << est_inter[i][j] << " ";
        }
    }

    std::cout << std::endl;
}

void rijndael::SubBytes()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            est_inter[i][j] = Sbox[est_inter[i][j]];
        }
    }
}

void rijndael::ShiftRows()
{
    int copy;
    int fila = 0;
    // fila 0 , se queda igual

    fila = 1; // rotamos una posicion
    copy = est_inter[fila][0];
    est_inter[fila][0] = est_inter[fila][1];
    est_inter[fila][1] = est_inter[fila][2];
    est_inter[fila][2] = est_inter[fila][3];
    est_inter[fila][3] = copy;

    fila = 2; // rotamos dos pos
    copy = est_inter[fila][0];
    est_inter[fila][0] = est_inter[fila][2];
    est_inter[fila][2] = copy;
    copy = est_inter[fila][1];
    est_inter[fila][1] = est_inter[fila][3];
    est_inter[fila][3] = copy;

    fila = 3; // rotamos tres pos
    copy = est_inter[fila][0];
    est_inter[fila][0] = est_inter[fila][3];
    est_inter[fila][3] = est_inter[fila][2];
    est_inter[fila][2] = est_inter[fila][1];
    est_inter[fila][1] = copy;
}

void rijndael::MixColumn()
{
   
    unsigned char a[4];
    unsigned char b[4];
    unsigned char c, j;
    unsigned char h;

    for (j = 0; j < 4; j++)
    {
        for (c = 0; c < 4; c++)
        {
            a[c] = est_inter[c][j];
            h = est_inter[c][j] & 0x80;
            b[c] = est_inter[c][j] << 1;
            if (h == 0x80)
                b[c] ^= 0x1B;
        }
        est_inter[0][j] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1];
        est_inter[1][j] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2];
        est_inter[2][j] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3];
        est_inter[3][j] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0];

    }
}

void rijndael::AddRoundKey(int iter)
{
    int j_ini = 4 * iter;
    std::cout << "Iteración " << iter << ": " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            est_inter[i][j] = est_inter[i][j] ^ expkey_[i][j + j_ini];
        }
    }

    std::cout << "Subclave = ";
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            std::cout << expkey_[i][j + j_ini] << " ";
        }
    }

    std::cout << " = ";

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            std::cout << est_inter[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

void rijndael::algoritmo()
{
    std::cout << "Clave: ";
    for (long unsigned int j = 0; j < key_.size(); j++)
    {
        for (long unsigned int i = 0; i < key_[j].size(); i++)
        {
            std::cout << std::hex << key_[i][j];
        }
    }

    std::cout << std::endl
              << "Bloque de texto original: ";
    for (long unsigned int j = 0; j < entrada_.size(); j++)
    {
        for (long unsigned int i = 0; i < entrada_[j].size(); i++)
        {
            std::cout << std::hex << entrada_[i][j];
        }
    }
    std::cout << std::endl;
    expan_key();

    AddRoundKey1();
    for (int iter = 1; iter < 10; iter++)
    {
        SubBytes();
        ShiftRows();
        MixColumn();
        AddRoundKey(iter);
    }
    // ultima iter
    SubBytes();
    ShiftRows();
    AddRoundKey(10);

    std::cout << std::endl
              << "Bloque de texto cifrado: ";
    for (long unsigned int j = 0; j < est_inter.size(); j++)
    {
        for (long unsigned int i = 0; i < est_inter[j].size(); i++)
        {
            std::cout << est_inter[i][j] << " ";
        }
    }
    std::cout << std::endl;
}
