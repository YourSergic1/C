#include "s21_string.h"

typedef struct {
  int minus_flag;

  int plus_flag;
  int space_flag;

  int width;

  int precision;

  int length_h;
  int length_l;

  int c;
  int d;
  int f;
  int s;
  int u;

  int error;
} options;

void reverse(char str[], int length) {
  //переварачивает строку
  char box[length + 1];

  for (int i = 0; i < length; i++) {
    box[length - 1 - i] = str[i];
  }
  box[length] = '\0';

  for (int i = 0; i < length; i++) {
    str[i] = box[i];
  }
}

void int_to_str(long int var, char *ptr, options *opt) {
  char *src = ptr;
  //переводит целое в строку
  if (var == 0) {
    if (opt->precision != 0) {
      *src = '0';
      src++;
    }
    int count_prec = 1;
    if (opt->precision > 0) {
      while (count_prec < opt->precision) {
        *src = '0';
        src++;
        count_prec++;
      }
    }
    if (opt->plus_flag == 1) {
      *src = '+';
      src++;
    } else if (opt->space_flag == 1) {
      *src = ' ';
      src++;
    }
    reverse(ptr, (int)s21_strlen(ptr));
    *src = '\0';
    src++;
  } else {
    int isNegative = 0;
    if (var < 0) {
      isNegative = 1;
      var = (-1) * var;
    }
    int count_prec = 0;
    while (var != 0) {
      int rem = var % 10;
      *src = (rem + '0');
      src++;
      var = var / 10;
      count_prec++;
    }
    if (opt->precision > 0) {
      while (count_prec < opt->precision) {
        *src = '0';
        src++;
        count_prec++;
      }
    }
    if (isNegative) {
      *src = '-';
      src++;
    } else if (!isNegative && opt->plus_flag == 1) {
      *src = '+';
      src++;
    } else if (opt->space_flag == 1) {
      *src = ' ';
      src++;
    }
    reverse(ptr, (int)s21_strlen(ptr));
    *src = '\0';
    src++;
  }
}

void unsigned_to_str(long unsigned int var, char *ptr, options *opt) {
  //переводит целое положительное в строку
  char *src = ptr;
  int count_prec = 0;
  while (var != 0) {
    int rem = var % 10;
    *src = (rem + '0');
    src++;
    var = var / 10;
    count_prec++;
  }
  if (opt->precision > 0) {
    while (count_prec < opt->precision) {
      *src = '0';
      src++;
      count_prec++;
    }
  }
  reverse(ptr, (int)s21_strlen(ptr));
  *src = '\0';
  src++;
}

void float_to_str(double var, char *src, options *opt) {
  //переводит число с плавующей точкой в строку
  int isNegative = 0;
  if (var < 0) {
    isNegative = 1;
    var = (-1) * var;
  }
  int main_part = (int)var;
  float dec_part = var - main_part;
  char box[11] = {0};
  int y = 0;
  while (main_part != 0) {
    int rem = main_part % 10;
    box[y] = (rem + '0');
    y++;
    main_part = main_part / 10;
  }
  if (isNegative) {
    box[y] = '-';
  } else if (!isNegative && opt->plus_flag == 1) {
    *src = '+';
    src++;
  } else if (opt->space_flag == 1) {
    *src = ' ';
    src++;
  }
  y = 0;
  reverse(box, (int)s21_strlen(box));
  while (y != (int)s21_strlen(box)) {
    *src = box[y];
    src++;
    y++;
  }
  if (opt->precision != 0) {
    *src = '.';
    src++;
    int repeater = 6;
    if (opt->precision > -1) repeater = opt->precision;
    for (int i = 0; i < repeater; ++i) {
      dec_part *= 10.0;
      dec_part += 0.00000006;
      *src = ((int)dec_part + '0');
      src++;
      dec_part -= (int)dec_part;
    }
  }
  *src = '\0';
  src++;
}

int char_to_int(const char *str) {
  //переводит строку в инт
  int result = 0;
  int sign = 1;
  int i = 0;
  if (str[0] == '-') {
    sign = -1;
    i++;
  }
  while (str[i] != '\0') {
    if (str[i] < '0' || str[i] > '9') {
      break;
    }
    result = result * 10 + (str[i] - '0');
    i++;
  }
  return result * sign;
}

void error_check(options *opt) {
  if (opt->plus_flag == 1 && (opt->c == 1 || opt->s == 1 || opt->u == 1))
    opt->error = 1;
  if (opt->space_flag == 1 && (opt->c == 1 || opt->s == 1 || opt->u == 1))
    opt->error = 1;
  if (opt->length_h == 1 && (opt->c == 1 || opt->s == 1 || opt->f == 1))
    opt->error = 1;
  if (opt->length_l == 1 && (opt->c == 1 || opt->s == 1 || opt->f == 1))
    opt->error = 1;
  if (opt->plus_flag == 1 && opt->space_flag == 1) opt->error = 1;
  if (opt->error == 1) {
    fprintf(stderr, "n/a");
    exit(0);
  }
}

const char *search_flags(const char *src, options *opt) {
  //ищет флаги +,-,' '
  while (1) {
    if (*src == ' ')
      opt->space_flag = 1;
    else if (*src == '-')
      opt->minus_flag = 1;
    else if (*src == '+')
      opt->plus_flag = 1;
    else
      break;
    src++;
  }
  return src;
}

const char *search_width(const char *src, options *opt, va_list args) {
  //ищет ширину
  if (*src == '*') {
    opt->width = va_arg(args, int);
    src++;
  } else {
    char width[11] = {0};
    int i = 0;
    while (*src > 47 && *src < 58) {
      width[i] = *src;
      i++;
      src++;
    }
    opt->width = char_to_int(width);
  }
  return src;
}

const char *search_precision(const char *src, options *opt, va_list args) {
  //ищет точность
  if (*src == '.') {
    src++;
    if (*src == '*') {
      opt->precision = va_arg(args, int);
      src++;
    } else {
      char width[12] = {0};
      int i = 0;
      while (*src > 47 && *src < 58) {
        width[i] = *src;
        i++;
        src++;
      }
      if (i == 0) {
        opt->precision = 0;
      } else {
        width[i] = '\0';
        opt->precision = char_to_int(width);
      }
    }
  }
  return src;
}

const char *search_length(const char *src, options *opt) {
  //ищет длину
  if (*src == 'l') {
    opt->length_l = 1;
    src++;
  } else if (*src == 'h') {
    opt->length_h = 1;
    src++;
  }
  return src;
}

const char *search_type(const char *src, options *opt) {
  //ищет тип
  if (*src == 'c')
    opt->c = 1;
  else if (*src == 'd')
    opt->d = 1;
  else if (*src == 'f')
    opt->f = 1;
  else if (*src == 's')
    opt->s = 1;
  else if (*src == 'u')
    opt->u = 1;
  else {
    opt->error = 1;
    fprintf(stderr, "n/a");
  }
  src++;
  return src;
}

void take_args(options opt, char *str, va_list args) {
  if (opt.d == 1 && opt.length_l != 1 && opt.length_h != 1) {
    int_to_str(va_arg(args, int), str, &opt);
  } else if (opt.d == 1 && opt.length_l == 1) {
    int_to_str(va_arg(args, long), str, &opt);
  } else if (opt.d == 1 && opt.length_h == 1) {
    int_to_str((short)va_arg(args, int), str, &opt);
  } else if (opt.u == 1 && opt.length_l != 1 && opt.length_h != 1) {
    unsigned_to_str(va_arg(args, unsigned), str, &opt);
  } else if (opt.u == 1 && opt.length_l == 1) {
    unsigned_to_str(va_arg(args, long unsigned), str, &opt);
  } else if (opt.u == 1 && opt.length_h == 1) {
    unsigned_to_str((short)va_arg(args, unsigned), str, &opt);
  } else if (opt.s == 1) {
    char *ptr = va_arg(args, char *);
    int repeater = opt.precision;
    while (*ptr != '\0' && repeater != 0) {
      *str = *ptr;
      str++;
      ptr++;
      repeater--;
    }
  } else if (opt.c == 1) {
    *str = va_arg(args, int);
  } else if (opt.f == 1) {
    float_to_str(va_arg(args, double), str, &opt);
  }
}

void width_work(char *str, options *opt) {
  //работает с шириной
  if (opt->width > (int)s21_strlen(str)) {
    // проверка на ширину
    if (opt->minus_flag == 1) {
      while (opt->width > (int)s21_strlen(str)) str[s21_strlen(str)] = ' ';
    } else {
      char box[2048];
      for (int i = 0; i < (int)s21_strlen(str); i++) {
        box[i] = str[i];
      }
      int difference = opt->width - (int)s21_strlen(str);
      for (int i = 0; i < opt->width; i++) {
        if (i < difference)
          str[i] = ' ';
        else {
          str[i] = box[i - difference];
        }
      }
    }
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  char *ptr = str;
  va_list args = {0};
  va_start(args, format);
  while (*format != '\0') {
    options opt = {0};
    opt.precision = -1;
    if (*format == '%') {
      format++;
      format = search_flags(format, &opt);
      format = search_width(format, &opt, args);
      format = search_precision(format, &opt, args);
      format = search_length(format, &opt);
      format = search_type(format, &opt);
      error_check(&opt);
      char str[2048] = "";
      take_args(opt, str, args);
      width_work(str, &opt);

      int i = 0;
      while (str[i]) {
        *ptr = str[i];
        i++;
        ptr++;
      }
    } else {
      *ptr = *format;
      ptr++;
      format++;
    }
  }
  *ptr = '\0';
  va_end(args);
  return (int)s21_strlen(str);
}