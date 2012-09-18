#ifndef __UTILS_H__
#define __UTILS_H__

#define SET_BIT(REG, BIT) _SFR_BYTE(REG) |= _BV(BIT) 
#define RESET_BIT(REG, BIT) _SFR_BYTE(REG) &= ~_BV(BIT)

#define PIN_ON(PORT, PIN) (_SFR_BYTE(PORT) & _BV(PIN))
#define PIN_OFF(PORT, PIN) (!(_SFR_BYTE(PORT) & _BV(PIN)))

#endif /* __UTILS_H__ */
