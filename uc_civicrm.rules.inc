<?php

/**
 * Alters the Ubercart order status update hook to run the 
 * syncing functions.
 */
function uc_civicrm_rules_action_info_alter(&$actions) {
  $order_arg = array(
    'type' => 'uc_order',
    'label' => t('Order'),
  );

  $actions['uc_order_update_status'] = array(
    'label' => t('Update the order status and sync with CiviCRM'),
    'group' => t('Order'),
    'base' => 'uc_civicrm_syncronize_status',
    'parameter' => array(
      'order' => $order_arg,
      'order_status' => array(
        'type' => 'text',
        'label' => t('Status'),
        'options list' => 'uc_order_action_update_status_options',
      ),
    ),
  );
}
