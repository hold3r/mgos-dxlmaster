#ifndef MGOS_DXLMASTER_H
#define MGOS_DXLMASTER_H

#include "mgos.h"

#ifdef __cplusplus
#include "DxlMaster.h"
#include "DynamixelConsole.h"
#else
typedef struct DynamixelDeviceTag DynamixelDevice;
typedef struct DynamixelConsoleTag DynamixelConsole;
typedef struct DynamixelMotorTag DynamixelMotor;
typedef struct DynamixelStatusTag DynamixelStatus;
typedef void (*userUartCb_t)(uint16_t, uint8_t *,  void *);
#endif

#ifdef __cplusplus
extern "C" {
#endif


DynamixelDevice *mgos_dxl_module_create(int model_id);
void mgos_dxl_master_begin(uint32_t baud);
void mgos_dxl_master_enable(uint8_t state);
DynamixelStatus mgos_dxl_init(DynamixelDevice *module);
void mgos_dxl_communicationSpeed(DynamixelDevice *module, uint32_t baud);
DynamixelStatus mgos_dxl_status(DynamixelDevice *module); 
DynamixelStatus mgos_dxl_ping(DynamixelDevice *module);
DynamixelStatus mgos_dxl_read(DynamixelDevice *module, uint8_t reg);
DynamixelStatus mgos_dxl_write(DynamixelDevice *module, uint8_t reg, uint8_t var);

DynamixelConsole *mgos_dxl_console_create(void);
void mgos_dxl_console_loop(DynamixelConsole *console);

DynamixelMotor *mgos_dxl_motor_create(int motor_id);
DynamixelStatus mgos_dxl_motor_init(DynamixelMotor *module);
void mgos_dxl_motor_wheelMode(DynamixelMotor *motor);
void mgos_dxl_motor_jointMode(DynamixelMotor *motor, 
                              uint16_t aCWLimit, 
                              uint16_t aCCWLimit);

void mgos_dxl_motor_enableTorque(DynamixelMotor *motor, bool aTorque);
void mgos_dxl_motor_speed(DynamixelMotor *motor, int16_t aSpeed);
void mgos_dxl_motor_goalPosition(DynamixelMotor *motor, uint16_t aPosition);
void mgos_dxl_motor_led(DynamixelMotor *motor, uint8_t aState);
uint16_t  mgos_dxl_motor_currentPosition(DynamixelMotor *motor);
DynamixelStatus  mgos_dxl_motor_getCurrentPosition(DynamixelMotor *motor, 
                                                   uint16_t *pos);

DynamixelStatus  mgos_dxl_motor_setComplianceMargins(DynamixelMotor *motor, 
                                                     uint8_t cw_margin, 
                                                     uint8_t ccw_margin, 
                                                     uint8_t cw_slope, 
                                                     uint8_t ccw_slope);

DynamixelStatus  mgos_dxl_motor_getComplianceMargins(DynamixelMotor *motor, 
                                                     uint8_t *cw_margin, 
                                                     uint8_t *ccw_margin, 
                                                     uint8_t *cw_slope, 
                                                     uint8_t *ccw_slope);

DynamixelStatus  mgos_dxl_motor_isMoving(DynamixelMotor *motor, 
                                         uint8_t *moving);

void mgos_dxl_setUserUartCb(userUartCb_t cb, void *arg);
void mgos_dxl_uartUserCb(uint16_t len, uint8_t *data);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // MGOS_DXLMASTER_H