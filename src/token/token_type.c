/**
 * @file   token_type.c
 * @brief  This file contains the to_string function for token_types.
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/token_type.h"

const char * token_type_to_string(token_type type) {
  switch(type) {
    case ENDMARKER:        return "Endmarker";
    case NAME:             return "Name";
    case INT:              return "Intger";
    case REAL:             return "Real";
    case STRING:           return "String";
    case NEWLINE:          return "Newline";
    case INDENT:           return "Indent";
    case DEDENT:           return "Dedent";
    case NODENT:           return "Nodent";
    case LPAR:             return "Lpar";
    case RPAR:             return "Rpar";
    case LSQB:             return "Lsqb";
    case RSQB:             return "Rsqb";
    case COLON:            return "Colon";
    case COMMA:            return "Comma";
    case SEMI:             return "Semi";
    case PLUS:             return "Plus";
    case MINUS:            return "Minus";
    case STAR:             return "Star";
    case SLASH:            return "Slash";
    case VBAR:             return "Vbar";
    case AMPER:            return "Amper";
    case LESS:             return "Less";
    case GREATER:          return "Greater";
    case EQUAL:            return "Equal";
    case DOT:              return "Dot";
    case PERCENT:          return "Percent";
    case LBRACE:           return "Lbrace";
    case RBRACE:           return "Rbrace";
    case EQEQUAL:          return "Eqequal";
    case NOTEQUAL:         return "Notequal";
    case LESSEQUAL:        return "Lessequal";
    case GREATEREQUAL:     return "Greaterequal";
    case TILDE:            return "Tilde";
    case CIRCUMFLEX:       return "Circumflex";
    case LEFTSHIFT:        return "Leftshift";
    case RIGHTSHIFT:       return "Rightshift";
    case DOUBLESTAR:       return "Doublestar";
    case PLUSEQUAL:        return "Plusequal";
    case MINEQUAL:         return "Minequal";
    case STAREQUAL:        return "Starequal";
    case SLASHEQUAL:       return "Slashequal";
    case PERCENTEQUAL:     return "Percentequal";
    case AMPEREQUAL:       return "Amperequal";
    case VBAREQUAL:        return "Vbarequal";
    case CIRCUMFLEXEQUAL:  return "Circumflexequal";
    case LEFTSHIFTEQUAL:   return "Leftshiftequal";
    case RIGHTSHIFTEQUAL:  return "Rightshiftequal";
    case DOUBLESTAREQUAL:  return "Doublestarequal";
    case DOUBLESLASH:      return "Doubleslash";
    case DOUBLESLASHEQUAL: return "Doubleslashequal";
    case AT:               return "At";
    case ATEQUAL:          return "Atequal";
    case RARROW:           return "Rarrow";
    case ELLIPSIS:         return "Ellipsis";
    case COLONEQUAL:       return "Colonequal";
    case OP:               return "Op";
    case AWAIT:            return "Await";
    case ASYNC:            return "Async";
    case TYPE_IGNORE:      return "Type Ignore";
    case TYPE_COMMENT:     return "Type Comment";
    case ERRORTOKEN:       return "Errortoken";
    case COMMENT:          return "Comment";
    case NL:               return "Nl";
    case ENCODING:         return "Encoding";
    case FALSE:            return "False";
    case NONE:             return "None";
    case TRUE:             return "True";
    case AND:              return "And";
    case AS:               return "As";
    case ASSERT:           return "Assert";
    case BREAK:            return "Break";
    case CLASS:            return "Class";
    case CONTINUE:         return "Continue";
    case DEF:              return "Def";
    case DEL:              return "Del";
    case ELIF:             return "Elif";
    case ELSE:             return "Else";
    case EXCEPT:           return "Except";
    case FINALLY:          return "Finally";
    case FOR:              return "For";
    case FROM:             return "From";
    case IF:               return "If";
    case IMPORT:           return "Import";
    case IN:               return "In";
    case IS:               return "Is";
    case IS_NOT:           return "Is Not";
    case LAMBDA:           return "Lambda";
    case NONLOCAL:         return "Nonlocal";
    case NOT:              return "Not";
    case NOT_IN:           return "Not In";
    case OR:               return "Or";
    case GLOBAL:           return "Global";
    case RAISE:            return "Raise";
    case RETURN:           return "Return";
    case TRY:              return "Try";
    case WHILE:            return "While";
    case WITH:             return "With";
    case YIELD:            return "Yield";
    case PASS:             return "Pass";
  }
  return NULL;
}
