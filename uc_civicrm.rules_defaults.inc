<?php
/**
 * @file
 * Default rules
 */

/**
 * Implements hook_default_rules_configuration().
 */
function uc_civicrm_default_rules_configuration() {
  // Default configuration to add a purchase.
  $rule = rules_reaction_rule();
  $rule->label = t('Add to CiviCRM on new order');
  $rule->active = TRUE;
  $rule->event('uc_checkout_complete');
  $rule->action('uc_civicrm_create_order_civicrm', array('order:select' => 'order', 'is_new' => TRUE));
  $configs['uc_civicrm_contact_on_order'] = $rule;

  // Default configuration to update a purchase.
  $rule = rules_reaction_rule();
  $rule->label = t('Update CiviCRM on order/status update');
  $rule->active = TRUE;
  $rule->event('uc_order_status_update');
  $rule->action('uc_civicrm_update_order_civicrm', array('order:select' => 'updated-order', 'is_new' => FALSE));
  $configs['uc_civicrm_contact_on_update'] = $rule;

  return $configs;
}
