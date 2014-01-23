<?php

/**
 * @file
 * This file contains the Rules hooks and functions necessary to make the order
 * related entity, conditions, events, and actions work.
 */

/**
 * Implements hook_rules_action_info().
 */
function uc_civicrm_rules_action_info() {
  $actions['uc_civicrm_create_order_civicrm'] = array(
    'label' => t('Add and update CiviCRM contact record'),
    'base' => 'uc_civicrm_action_order_civicrm',
    'parameter' => array(
      'order' => array('type' => 'uc_order', 'label' => t('Order')),
      'is_new' => array('type' => 'boolean', 'label' => t('Is new?')),
    ),
  );
  $actions['uc_civicrm_update_order_civicrm'] = array(
    'label' => t('Update CiviCRM contact record'),
    'base' => 'uc_civicrm_action_order_civicrm',
    'parameter' => array(
      'order' => array('type' => 'uc_order', 'label' => t('Order')),
      'is_new' => array('type' => 'boolean', 'label' => t('Is new?')),
    ),
  );
  return $actions;
}
